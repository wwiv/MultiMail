/*
 * MultiMail offline mail reader
 * conversion tables ISO 8859-1 <-> IBM codepage 437

 Copyright 1997 Peter Karlsson <peter@softwolves.pp.se>,
                Toth Istvan <stoty@vma.bme.hu>
 Copyright 1998-2015 William McBrine <wmcbrine@gmail.com>

 Distributed under the GNU General Public License.
 For details, see the file COPYING in the parent directory. */

#ifndef CONVTAB_H
#define CONVTAB_H

extern bool isoConsole; // ISO8859-1 <--> CP437 (DOS) conversion?

extern const char *dos2isotab;
extern const char *iso2dostab;

char *charconv_in(char *);
char *charconv_out(char *);
char *letterconv_in(char *);
char *letterconv_out(char *);
char *areaconv_in(char *);
char *areaconv_out(char *);

#endif
