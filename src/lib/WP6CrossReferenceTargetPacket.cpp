/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/* libwpd
 * Version: MPL 2.0 / LGPLv2.1+
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU Lesser General Public License Version 2.1 or later
 * (LGPLv2.1+), in which case the provisions of the LGPLv2.1+ are
 * applicable instead of those above.
 *
 * For further information visit http://libwpd.sourceforge.net
 */

/* "This product is not manufactured, approved, or supported by
 * Corel Corporation or Corel Corporation Limited."
 */

#include "WP6CrossReferenceTargetPacket.h"
#include "libwpd_internal.h"

WP6CrossReferenceTargetPacket::WP6CrossReferenceTargetPacket(librevenge::RVNGInputStream *input, WPXEncryption *encryption, int /* id */, unsigned dataOffset, unsigned dataSize) :
	WP6PrefixDataPacket(input, encryption),
	m_name()
{
	_read(input, encryption, dataOffset, dataSize);
}

WP6CrossReferenceTargetPacket::~WP6CrossReferenceTargetPacket()
{
}

void WP6CrossReferenceTargetPacket::_readContents(librevenge::RVNGInputStream *input, WPXEncryption *encryption)
{
	// The packet is the target name as a sequence of WordPerfect character words
	// (low byte = character, high byte = character set), terminated by a null
	// word. Decode each through the WP6 character map, exactly as a font name.
	const unsigned maxWords = getDataSize() / 2;
	for (unsigned i = 0; i < maxWords; i++)
	{
		unsigned short charWord = readU16(input, encryption);
		auto characterSet = (unsigned char)((charWord >> 8) & 0x00FF);
		auto character = (unsigned char)(charWord & 0x00FF);

		if (character == 0x00 && characterSet == 0x00)
			break;

		const unsigned *chars;
		int len = extendedCharacterWP6ToUCS4(character, characterSet, &chars);
		for (int j = 0; j < len; j++)
			appendUCS4(m_name, chars[j]);
	}
	WPD_DEBUG_MSG(("WordPerfect: Cross-Reference Target name: %s\n", m_name.cstr()));
}
/* vim:set shiftwidth=4 softtabstop=4 noexpandtab: */
