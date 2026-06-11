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

#ifndef WP6CROSSREFERENCEGROUP_H
#define WP6CROSSREFERENCEGROUP_H

#include "WP6VariableLengthGroup.h"
#include <librevenge/librevenge.h>

// Cross-Reference Group - Function 213 (0xD5). Subfunctions are paired: even
// codes turn a reference On, odd codes turn it Off, and the cached display text
// of the reference (e.g. the page number) is the document text between them.
// The On code's non-deletable data is the target name (the tag ID the reference
// points at), stored as a null-word-terminated WordPerfect wide string.
class WP6CrossReferenceGroup : public WP6VariableLengthGroup
{
public:
	WP6CrossReferenceGroup(librevenge::RVNGInputStream *input, WPXEncryption *encryption);
	void _readContents(librevenge::RVNGInputStream *input, WPXEncryption *encryption) override;
	void parse(WP6Listener *listener) override;

private:
	librevenge::RVNGString m_targetName;
};

#endif /* WP6CROSSREFERENCEGROUP_H */
/* vim:set shiftwidth=4 softtabstop=4 noexpandtab: */
