
/******************************************************************************
* MODULE     : page_item.cpp
* DESCRIPTION: A typesetted document consists of an array of page_items.
*              Each page item contains spacing and page breaking information.
* COPYRIGHT  : (C) 1999  Joris van der Hoeven
*******************************************************************************
* This software falls under the GNU general public license and comes WITHOUT
* ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for more details.
* If you don't have this file, write to the Free Software Foundation, Inc.,
* 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
******************************************************************************/

#include "Format/page_item.hpp"
#include "Boxes/construct.hpp"

/******************************************************************************
* Routines for the page item class
******************************************************************************/

page_item_rep::page_item_rep (box b2, array<lazy> f2, int n2):
  type (PAGE_LINE_ITEM), b (b2), spc (0), penalty (0), fl (f2), nr_cols (n2) {}
page_item_rep::page_item_rep (tree t2, int nr_cols2):
  type (PAGE_CONTROL_ITEM), b (empty_box (decorate ())), spc (0),
  penalty (HYPH_INVALID), nr_cols (nr_cols2), t (t2) {}
page_item_rep::page_item_rep (int tp2, box b2, space spc2, int pen2,
			      array<lazy> fl2, int nr_cols2, tree t2):
  type (tp2), b (b2), spc (spc2), penalty (pen2),
  fl (fl2), nr_cols (nr_cols2), t (t2) {}

page_item::page_item (box b, array<lazy> lz, int nr_cols):
  rep (new page_item_rep (b, lz, nr_cols)) {}
page_item::page_item (tree t, int nr_cols):
  rep (new page_item_rep (t, nr_cols)) {}
page_item::page_item (int type, box b, space spc, int penalty,
		      array<lazy> fl, int nr_cols, tree t):
  rep (new page_item_rep (type, b, spc, penalty, fl, nr_cols, t)) {}
bool page_item::operator == (page_item item2) { return rep==item2.rep; }
bool page_item::operator != (page_item item2) { return rep!=item2.rep; }
page_item copy (page_item l) {
  return page_item (l->type, l->b, l->spc, l->penalty,
		    l->fl, l->nr_cols, l->t); }

ostream&
operator << (ostream& out, page_item item) {
  switch (item->type) {
  case PAGE_LINE_ITEM:
    return out << "line (" << item->b << ")";
  case PAGE_CONTROL_ITEM:
    return out << "control (" << item->t << ")";
  }
  return out << "unknown";
}
