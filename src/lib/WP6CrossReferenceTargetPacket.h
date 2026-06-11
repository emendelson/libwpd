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

#ifndef WP6CROSSREFERENCETARGETPACKET_H
#define WP6CROSSREFERENCETARGETPACKET_H

#include "WP6PrefixDataPacket.h"

// Prefix Packet Type 15 (0x0F): Cross-Reference Target. Holds the name of a
// cross-reference target as a null-word-terminated WordPerfect wide string. A
// body Cross-Reference Tag (Character group 0xD4 subfunction 0x08) references
// this packet by prefix ID to mark the target's position in the document.
class WP6CrossReferenceTargetPacket : public WP6PrefixDataPacket
{
public:
	WP6CrossReferenceTargetPacket(librevenge::RVNGInputStream *input, WPXEncryption *encryption, int id, unsigned dataOffset, unsigned dataSize);
	~WP6CrossReferenceTargetPacket() override;
	void _readContents(librevenge::RVNGInputStream *input, WPXEncryption *encryption) override;
	void parse(WP6Listener * /*listener*/) const override {}
	const librevenge::RVNGString &getName() const
	{
		return m_name;
	}

private:
	WP6CrossReferenceTargetPacket(const WP6CrossReferenceTargetPacket &);
	WP6CrossReferenceTargetPacket &operator=(const WP6CrossReferenceTargetPacket &);
	librevenge::RVNGString m_name;
};

#endif /* WP6CROSSREFERENCETARGETPACKET_H */
/* vim:set shiftwidth=4 softtabstop=4 noexpandtab: */
