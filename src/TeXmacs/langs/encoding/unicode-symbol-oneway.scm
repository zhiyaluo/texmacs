;; One-way conversion of some Unicode characters to TeXmacs symbols.

;; (C) 2003  David Allouche
;;
;; This software falls under the GNU general public license and comes WITHOUT
;; ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for details. If
;; you don't have this file, write to the Free Software Foundation, Inc., 59
;; Temple Place - Suite 330, Boston, MA 02111-1307, USA.

;; Those symbols have a sensible unicode translation, so they can be exported.
;; But another symbol was chosen for the importation of the corresponding
;; unicode character. So the exportation is one-way only.

;; NOTE: This file must be reversed when loaded by the translator.
;;       The order (symbol unicode) is used for consistence with other tables.

;;; Angle brackets

;; These characters are canonically equivalent to CJK punctuations, but MathML
;; retained their mathematic use for backwards compatibility (though recent
;; revisions of Unicode explicitely discourage this).

("<langle>"	"#2329")
("<rangle>"	"#232A")

;;; Ambiguous characters

;; Omega and MathML both agree that <barwedge> should be exported as #2305
;; (PROJECTIVE), but this symbol must also be used to display NAND (until a
;; nand symbol is defined, at least).

("<barwedge>"	"#22BC") ; NAND
