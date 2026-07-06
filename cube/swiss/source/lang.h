/* lang.h - minimal UI localization for Swiss.

   Strings are translated gettext-style, keyed on their English source text, so
   call sites only need to wrap a literal in _( ). Any string without a Russian
   entry falls back to the English original, so partial coverage is safe. */
#ifndef LANG_H
#define LANG_H

enum uiLanguage {
	UILANG_ENGLISH = 0,
	UILANG_RUSSIAN,
	UILANG_MAX
};

// Native names for the language selector (not themselves translated).
extern char *uiLanguageStr[];

// Returns the translation of en for the active UI language, or en unchanged
// when the active language is English or no translation exists. Returns char *
// (not const) to match Swiss's pervasively non-const string handling.
char *_(const char *en);

#endif
