Revision History
================

## 0.49 - 2007/07/19:

- Built against PDCurses 3.3 (and 3.1 is now the minimum version that
  will work); removed XCURSES references, for the sake of PDCurses 3.2+.
  This is faster, and allows me to finally chuck the resize_term()
  kludge introduced in 0.42 (for the problem where the window scrolled
  up on return from shelling out in Win32).

- You can now use the "Transparency" keyword with PDCurses -- with the
  SDL port, you can achieve the same effects as in, e.g., Gnome Terminal
  with ncurses.

- I'm distributing the Win32 binary with pdcurses.dll dynamically
  linked, purely so that you can swap it out with the SDL version if you
  like (see http://pdcurses.sf.net/). It's fun to play with. :-)

- In "animate" mode, the ANSI viewer now pauses after each character.
  This feature was omitted for a long time because the animation was
  slow enough on older machines, and the shortest possible delay was
  still too long. But animated mode is useless nowadays without it.

- If the config files can't be written (updated), MultiMail no longer
  aborts with an error; instead, a message is displayed, with a pause,
  and it continues.

- Updated to GPL version 3.

## 0.48 - 2007/04/04:

- This version now builds with PDCurses 3.0, and if using PDCurses, will
  no longer build with an earlier version. This gives us mouse support
  for DOS and OS/2, and better idling in the XT version, among other
  improvements.

- New keyword: "Mouse". Setting it to "No" turns off support for mouse
  input. Mainly this is to allow disabling of the mouse cursor; it also
  means you can select without holding shift in X11.

- Use setlocale(), to give a correct display in environments such as the 
  console under Ubuntu.

- The FAQ and TODO files were outdated, and not very useful.

- Removed the makefiles for EMX and Borland C++ for Windows. These
  compilers are basically dead. I also removed Makefile.wid -- full-
  fledged wide-character support will be coming in the future, but for
  now, this file was just more clutter.

- Changed "install" to a double-colon rule in Makefile to avoid conflict 
  with INSTALL on non-case-sensitive filesystems, like Mac OS X's HFS+.

## 0.47 - 2005/12/31:

### New features:

- Added support for Microsoft Visual C++, MinGW, and Open Watcom. I highly
  recommend Watcom, and I'm now using it for the OS/2 port. I'd use it for
  the Win32 port, but sadly the directory scan (used in the packet list)
  is using the slow POSIX-emulation method rather the fast native method,
  and I haven't got that sorted out yet. MinGW is also very nice, and I'd
  use that, except that it needs MSVCRT.DLL, which doesn't come with old
  Windows 95. So -- rather than continuing with the 5-year-old Borland 5.5
  (although it still works) -- I'm delivering an MSVC-built version. This
  version doesn't support set_new_handler(), but no one is likely to
  notice (famous last words). Also, I've finally dropped the pretense of
  supporting RSX/NT.

- The starting directory and home directory are now added to the PATH
  searched for archivers and editors, so you can include them in the same
  directory with mm.exe. I'm taking advantage of this to bundle InfoZip's
  zip and unzip, hugely bloating the Windows zip, but hopefully stopping
  the complaints I get from people who can't figure out how to set up
  archiving themselves.

- Support for the "GreekQWK" variant, which uses 0x0C instead of 0xE3 as
  the line delimiter. Reported by Dimitris Mandalidis. Note that there's
  still no particular support for the Greek _character set_, but you can
  probably make it work by disabling character set conversion.

- A mouse click in the lower half of the screen, in the ANSI viewer, now
  counts as if the spacebar had been pressed, instead of PgDn. Also, when
  the screen is at the start, even clicking in the top half counts as a
  space. This makes for easier mouse-only navigation with the new welcome
  screen display.

- Included Makefile.wid for wide-character ncurses. This doesn't really do
  anything yet, except give you the proper background character instead of
  the octothorpe, and work semi-decently in a UTF-8 Linux VT. For now, I
  don't recommend using it, nor distributing binaries based on it.

- Various documentation updates.

### Bug fixes and such:

- Revisions for newest version of PDCurses -- fewer ifdefs needed. Note
  that MultiMail now must be compiled with PDCurses 2.7 or later.

- Changed some compiler options to work better with recent gcc.
  Unfortunately it bloats the executable.

- Removed the distinction between Bulletins and New file lists, so there's
  only one prompt to bother you with now.

- Minor code cleanup.

## 0.46 - 2003/12/31:

### New features:

- First, an apology: This version probably should've come out in July, when
  most of these changes were done... though there was a bug in one of the
  new features that didn't show up until Halloween.

- MultiMail now displays the appropriate screens (when it can determine
  them) on opening and closing a packet, instead of just adding them to the
  bulletin list. This is more like the way most other OLRs work (though not,
  e.g., Blue Wave). I hope you like it. :-) I had to adjust to it myself,
  but now I wouldn't go back.

- The ANSI viewer now includes partial support for AVATAR (level 0) and
  BSAVE (.BSV; text-only). As with the parsing of AT codes, these can be
  toggled, via ^V and ^B respectively.

- The lower portion of the area list display has been redesigned. It now
  includes the name of the Door and BBS that created the packet, if
  available, and omits the duplicate description. The field formerly
  labelled "BBS:" is now "Name:"; "BBS:" is used for the software type
  instead. In the upper portion, there's a little more room for the
  descriptions. Door type in OPX mode is not entirely satisfactory; some SX
  doors seem to use the field for BBS version instead. Neither of the new
  fields is available in Blue Wave mode.

### Bug fixes and such:

- With this version, I've added MIPS and AMD64 to my list of tested systems
  (no mods needed). However, I'm not including those binaries, because a)
  the MIPS binary I built is only for a Tivo, and doesn't display onscreen
  anyway, so you'd have to telnet in or use a serial console; and b) there's
  a small but annoying bug in the (beta) version of ncurses used on SF.net's
  AMD64 compile farm machine, such that the window borders all show up with
  the wrong color. (The problem is not actually 64-bit related. Also, please
  note that MultiMail itself has been 64-bit ready for a long time, since
  being ported to the Alpha processor.)

- Fix for some incorrect CONTROL.DAT files -- a failed read (because a file
  was too short) was returning a dupe of the last line; now returns a blank.

- Make reply endings in OPX conform better to what SX does -- CR/LF, and a
  trailing zero. (I noticed that the tearline was being eaten by the Wildcat
  SX door on Doc's Place, and there was _no_ final CR/LF... I don't think it
  used to do that, but anyway, this fixes it.)

- ANSI viewer: Allowed right arrow to exit even in lynxNav mode -- makes
  more sense with new Hello/Goodbye behavior; fewer false positives when
  interpreting AT codes; better handling of chars 0-31 and some others,
  under ncurses; no more overlapping of screens when a screen clear command
  is rendered.

- Some code simplification.

## 0.45 - 2003/06/08:

### New features:

- New temporary directory and file system: Instead of using tmpnam() --
  which frankly never worked properly outside of Unix, and is sometimes
  regarded as a security risk there -- MultiMail now generates temp
  directories of the form "workNNNN", where NNNN is a random number, under
  the directory specified by the new .mmailrc keyword "TempDir". By default,
  TempDir is set to the same value as mmHomeDir. NOTE THAT IF YOU'VE BEEN
  USING ENVIRONMENT VARAIBLES TO SPECIFY A TEMP DIR, IT WILL NO LONGER WORK.
  They aren't even used to set the default (as with EDITOR). In the XT port,
  TempDir also now specifies the location of the swap file, if that feature
  is enabled. And temporary files are now created as "tmpNNNNN.txt" under
  the workNNNN directory, where NNNNN is a serial number; so they no longer
  clutter the base temp directory, they have the ".txt" extension some
  editors depend on, and there's no longer a problem with editor-created
  backup files being cleared out.

- Big improvements in the ANSI viewer under Unix: For those terminals (like
  the Linux console) that support the "smpch" terminfo capability, the IBM
  PC characters are passed through directly. For other terminals (like
  xterm), the use of the widely unimplemented ACS_BLOCK and ACS_BOARD has
  been replaced with an inverse space and ACS_CKBOARD, respectively. (In
  ncurses' curses.h, ACS_BLOCK and ACS_BOARD are identified as "Teletype
  5410v1 symbols", while ACS_CKBOARD is in the "VT100 symbols" group.
  Everything supports VT100, but few terminals support the other class.)
  Note that the use of the inverse space does present a problem when
  characters have the A_BOLD attribute, as it's interpreted differently by
  different terminals, so that some will make the cell "bright", and some
  won't; but this seems to look best on the greatest number of terminals.
  Also note that "xterm -fn vga -tn linux" is still the best way to view
  ANSI under X. ;-)

- A new method for setting mmHomeDir: If it's based on the environment
  variable "HOME", add "mmail" to the end, as before; but if it's based on
  "MMAIL" or the start directory, don't. Practically speaking, this should
  make it apply "mmail" under Unix and not under DOS-ish systems, in most
  cases. That means that if you create a directory like "C:\MMAIL" and run
  mm.exe from there, it will no longer create "C:\MMAIL\MMAIL\DOWN", etc.,
  but simply "C:\MMAIL\DOWN". Note that this (unlike the new temp system)
  applies only to new installations; upgrades will not alter existing
  MMAIL.RC pathnames.

- The name shown at the top of the screen is now "MultiMail/Sysname vX.X" --
  i.e., the same as would appear in a QWK reply tearline -- instead of
  "MultiMail offline reader vX.X". Shorter, yet more informative. :-)

### Bug fixes and such:

- Doing a ^X during a bulletin would cause a segfault.

- A malformed 'H' command (e.g., using "0" as a parameter) in ANSI could
  cause a segfault.

- The window title is explicitly set to "MultiMail" in the Win32 and XCurses
  ports. This eliminates the problem where "UNZIP" would remain in the title
  after unarchiving a packet under Win 9x.

- Revived cursor mode save/restore routines for PDCurses (except for Win32,
  where it doesn't work); moved cursor restoration after endwin() call in
  mysystem() (this is why it didn't do the job before).

- Updated Makefiles for PDCurses 2.6, and GCC 3.2.1 (in the case of EMX). I
  strongly recommend upgrading to PDCurses 2.6, in most cases, as it already
  incorporates my patch for halfdelay(); however, there's a fatal bug in the
  OS/2 version. (Write me for a patch.) I also recommend ncurses 5.3 over
  5.2 -- for one thing, it fixes the problem with the bool declaration that
  broke searching and animation in some installations -- but I've left it as
  5.2 in the Makefile, for now, because I have too many systems to recompile
  it for. :-)

- Remaining compilation warnings eliminated for most platforms: Got rid of
  tmpnam() (see above), moved "%y" strftime() strings outside the calls
  (copied this from Ingo Brueckl), and added "-Wno-deprecated" to the
  Makefile options for the latest versions of gcc.

- Useless .mmailrc keyword "homeDir" removed. (It specified the base value
  for mmHomeDir, but in most cases that was already specified explicitly on
  the very next line.)

- Stronger attempts to use backslash characters instead of slash where
  appropriate in MMAIL.RC (depending on the platform). But again, this is
  cosmetic.

- Optimizations, comments, etc.

## 0.44 - 2003/05/07:

### New features:

- Added the pipe character, '|', as an alternative to '^' for invoking the
  filter function. It turns out that '^' is a poor choice for many non-U.S.
  keyboards; sorry. The pipe character is also somewhat more consistent with
  other programs with similar functions. Problem reported by Peter Karlsson.

### Bug fixes and such:

- Changed the way that the length of QWK replies is calculated. This is a
  speculative fix for a reported problem with corrupt replies that I
  couldn't reproduce; but from what was described, this _should_ do it. At
  any rate, the new code is simpler and cleaner. Reported by Jimmy Day et
  al.

- Pressing the "END" key in string input fields now works correctly, taking
  the cursor to the end of the field instead of ending the edit. Reported by
  Touko Rajala.

- Bogus/unintentional '@' color code sequences could cause segfaults in the
  ANSI viewer. Reported by Neall Mercado.

- In the Win32 version, under NT (though not 9x), the temporary directories
  were not being deleted.

- The filter was not working correctly in the LittleAreaListWindow.

- Junk could appear in the LetterList on a resort if some messages were
  read.

- Narrowed the width of some windows as a workaround for display bugs in
  xterm.

- Added "-inul" to the default command lines for RAR to suppress the output.

- Minor internal changes to allow compilation and remove warnings under
  Sun's SUNWspro C++ compiler. This also entailed the elimination of the
  sillier of the "set_Letter_Params()" functions, which was long overdue.
  :-)

- Miscellaneous small changes for efficiency.

## 0.43 - 2002/03/09:

### New features:

- A big one: Filter feature in all list windows, invoked by pressing '^'
  (shift-6). See the "FILTERING" section of the man page for details. This
  was inspired by similar features in the Pan and BNR newsreaders.

- Clock in the upper right corner of the letter window. (I would've added it
  to the others, but they lack an obvious place to put it. I figured that
  one spends most of one's time in the letter window anyway.) It can show
  time of day, time since startup, or be disabled, as controlled by the new
  keyword "ClockMode". Note that this required changes to the keyboard
  routines (now using halfdelay() instead of a blocking call), which in turn
  affected the ability of MultiMail to give up CPU time when idling. Most
  ports still use little CPU, but the XT version pegs it high, except under
  DOSEmu. (Old versions of DOSEmu, ironically, instead show high CPU usage
  with the new DOS (DPMI) version, which doesn't have that problem under
  Windows or OS/2.) Also, I had to fix PDCurses to make this work -- write
  to me if you want the patch.

- "AT code" parser for the ANSI viewer, for PCBoard and Wildcat '@' color
  codes. (I've only seen these used in the sample packets that came with a
  few readers -- do they exist in the wild?) Also, "ANSI music", though
  still not played, is now filtered out, so at least it doesn't clutter the
  image.

- The "UseColors" keyword is now available in the PDCurses (DOSish) ports.
  That means a monochrome mode, which should help on some displays.

- The packet name is now displayed when in the letter list, letter window or
  ANSI viewer. No more having to back out to check. :-) The placement of the
  packet name in the area list window has been changed for consistency.

- The tagline window can now be sorted, optionally.

- An "Opening..." notice is now displayed when entering an area, as when
  opening a packet. (This operation can be slow, so it's good to have a hint
  that MultiMail got the message.)

### Bug fixes and such:

- The type 'm' (Unix mailbox) parser in the SOUP module was missing some
  valid "From " separators, so I incorporated code based on the VALID macro
  from the C-Client library by Mark Crispin. I've read conflicting claims
  about whether its "free-fork" license is GPL-compatible, but since I don't
  see a better way to do this, I've chosen to assume that it is, at least for
  now. Anyway, this may in fact be the _only_ valid (no pun intended) way to
  parse a Unix mailbox without false positives or negatives.

- The ANSI viewer was not displaying the headers of SOUP messages when
  animating them, or thereafter. This was really a problem with multiblock
  messages (otherwise not noticeable except in the XT version, and then only
  with a message over 64K). Also, the ANSI viewer now acknowledges "expert"
  mode (i.e., it omits the "F1 or ? - Help" message from the lower right).

- The address book and tagline windows now show the number of items, like
  the other lists.

- In an xterm, when the tagline window was active, bits of the scroll bar
  and the screen border were being replaced with blanks. I've fixed this in
  an ad hoc way, but I'm not quite sure what caused it.

- An empty file list in the packet window caused problems. Normally you
  wouldn't see this, because there's always at least a ".." entry for the
  parent directory. But the filesystem on a Windows CE device apparently
  lacks them, as I found when running MultiMail/XT under PocketDOS.

- Setting the "UseColors" keyword to "No" now forces the use of the default
  colors (or rather, the monochrome version of them), as the .mmailrc
  comment had already claimed it did, instead of the monochrome version of
  the colors specified by "ColorFile".

- The "Reverse" attribute will no longer be stripped from a color file
  that's rewritten by a PDCurses (DOSish) port.

- If the tagline file existed, but was completely empty, a segfault would
  occur on selecting the (nonexistent) tagline when composing a message.
  Reported by Touko Rajala.

- Some really basic stuff added to the man page -- it always should've been
  there. Further revision is needed.

- Minor speedups.

## 0.42 - 2001/12/08:

### New features:

- CTRL-E instead of 'E' now forces invocation of the addressbook when
  entering a message in a non-netmail, non-email area. This only gets you
  the real name portion. I don't really see the use of this myself -- the
  entire point of the addressbook is to store netmail and email addresses,
  not simple names -- but it was requested, and easy to do, so here it is.
  It works wherever 'E' works (area list, letter list, letter window),
  although due to space considerations and laziness, it only appears in the
  letter list's help menu. Note that you can still only use the 'L' function
  of the addressbook on messages where an address is present. (Changing that
  would be more involved.) Suggested by Greg Sears.

### Bug fixes and such:

- In the Win32 version, under Windows XP and perhaps 2000 (?), the window
  was scrolled up on returning from a shell (unarchiving, etc.), unless the
  scrollback buffer was disabled. Although cosmetic, this was enough of a
  nuisance that I'm releasing 0.42 now.

- Added strings.h to the includes in mmail.h to get it to compile under QNX.
  (If you're trying this, edit the Makefile to say "-lncurses" rather than
  "-lcurses".) Note that the background characters (ACS_BOARD and
  ACS_CKBOARD) aren't what they should be in QNX; otherwise, it works well.

- New error message for the case when no files are found in the work
  directory after uncompression, but no error code was returned by the
  unarchiver. (Previously this resulted in the misleading message "Packet
  type not recognized"; that message is now reserved for times when there
  are actually some files in the work directory.)

- Since version 0.38, when I moved development to a new computer, the
  documentation file "mm.txt", included with the DOSish ports, had not been
  converted correctly by the script that builds those archives -- it was
  left as raw troff code instead of a rendered man page, and the line
  endings were left as LF (Unix style). In other words, it was basically
  illegible. The discouraging part of this is that no one reported it, which
  makes me think that no one's reading the documentation. :-(

- Other, minor updates to the documentation.

## 0.41 - 2001/10/16:

### New features:

- Options can now be specified on the command line. Any .mmailrc option may
  be used, though not all will actually work (some of them are used in
  initialization before this point). Options are preceded by '-' or "--",
  and must finish before a packet is specified. See the man page for more
  details.

- New keyword: "IgnoreNDX". This makes MultiMail ignore the *.NDX files in
  QWK packets, in favor of the new (slower, but safer) indexing method that
  uses only MESSAGES.DAT. Turn this on if you get bogus *.NDX files from
  your BBS (as seems all too common).

### Bug fixes and such:

- Big bug: Reply splitting in QWK on DOSish systems (DOS, Win32, OS/2)
  generated a corrupt reply packet (always). It's been this way a long time;
  possibly since the message split feature was introduced. I never noticed
  it because a) I rarely split messages, b) I seldom use QWK anymore -- all
  SOUP and BW now, c) I never use the DOSish ports, except for testing, and
  d) the split replies _look_ OK, until you close and reopen the packet. I
  had a lot of bug reports which, in retrospect, seem to be about this, but
  I never got enough detail to make sense of the problem, until Ken Hrynchuk
  reported on it. Many thanks to him.

- Bogus values in the *.NDX files of a QWK packet are now checked for and
  often handled without having to abort. In some cases, MultiMail is able to
  revert to the alternate indexing method automatically; in others, the
  message "ERROR READING MESSAGES.DAT" appears in the letter list, instead
  of the gibberish that resulted when following a bogus pointer. For those
  cases which still cause problems, see the new "IgnoreNDX" keyword.

- Problems with the ncurses configuration on Mandrake 8 (well, on my system,
  anyway) caused MultiMail to hang on searches or ANSI animation. There's
  now a partial workaround for this (searching works OK, ANSI anim still
  hangs) in MultiMail. But the proper fix is this: Download the ncurses
  source; configure; manually edit the line in curses.h that defines bool to
  say "typedef unsigned char bool" instead of "typedef unsigned bool";
  compile; and install. I still have to figure out why the typedef comes out
  that way; the same version of ncurses (with the same configure script)
  works correctly on my old Slackware system. You might see this problem on
  other systems as well.

- Blue Wave messages with Internet kludge lines (as produced by version 4
  doors) were causing segfaults. This is what happens when a feature doesn't
  get exercised for a while. :-(

- Segfault on a message with a MSGID kludge line, but no other body text.

- In the Win32 port, packet time stamping now works under Win 9x, though it
  still doesn't work on network shares under NT.

- Some unprintable characters weren't being filtered out when running in an
  xterm, resulting in a garbled display.

- In the 16-bit port, in QWK packets with no *.NDX files, MultiMail was
  failing if the MESSAGES.DAT file was larger than 32K.

- The END key now works under screen (for example) with ncurses.

- The message-splitting function now uses parentheses instead of brackets,
  and the part number is padded with leading zeroes. I did this to match
  standard practice in the alt.binaries.* newsgroups.

- Added the undocumented option "-#" to the default command lines for PKZip
  and PKUnzip. This suppresses output, equivalent to the "-q" option used in
  the default InfoZip command lines. Suggested by K.H. (Note that if you're
  upgrading, you'll have to put it in manually, if you want it; as always,
  MultiMail won't alter values that are already specified in its config
  file.)

- Shelled commands (zip, unzip, edit) can now handle paths with spaces in
  them.

- On MultiMail's first run, on DOSish systems, the MMAIL.RC ended up with
  paths that had a mix of slash and backslash characters. Although this
  didn't interfere with operation, it was a cosmetic defect.

- The defaults in the top-level Makefile have changed to "<curses.h>" for
  CURS_INC, and "-lcurses" for LIBS. Most/all distros of Linux, as well as
  FreeBSD, have replaced the older curses with ncurses by now, and some
  (e.g., Debian) lack the old-style compatibility links, so this now seems
  to be the most widely compatible configuration. (The old defaults are now
  in the first commented-out example section.)

- I figured out the problem that led to the hasty release of version 0.40 --
  it was a missing pair of parentheses. <sigh> Or to look at it another way,
  a misunderstanding of operator precedence.

## 0.40 - 2001/04/15:

### New features:

- Nothing new this time.

### Bug fixes and such:

- Undid one part of the BSOC, which (perversely enough, since this is exactly
  what it was intended to cut down on) was causing crashes in the Win32, XT,
  and OS/2 ports. I still haven't nailed down WHY it was doing this, but I
  isolated the source of the trouble by brute-force analysis. :-( I promise
  better testing next time.

- Useless mouse code now omitted in DOS, XT and OS/2 ports. (Yes, I hope to
  actually support the mouse on these platforms eventually. First, mouse
  support has to be added to their respective ports of PDCurses.)

## 0.39 - 2001/04/13:

### New features:

- Mouse functionality. Currently, this is only supported under X (with
  either ncurses or PDCurses), in the Linux console with gpm, and in the
  Win32 port. See the man page for a description of how to use this -- not
  well-described there, but it should be fairly intuitive.

- A new flag to join Marked, Replied, Read and Private: Saved. It's set
  automatically when a message is saved (natch). It appears in the letter
  list as a lowercase 's', and as a new flag in the group displayed in the
  letter window. (Note that if the message is also Marked, only the 'M' will
  appear in the letter list -- I was short of columns.) Because of this, the
  names displayed in the letter window have been shortened. Saving a message
  no longer marks it as Read, since that seems redundant now (though it
  still does clear the Marked flag). The new flag is mapped appropriately in
  .XTI files, but not in MAIL.FDX, so it's not preserved in OPX packets.

- New transparency method: The transparent background color is the one
  specified by "Main_Back" in the colors file, rather than always black.
  This allows the use of transparency with light backgrounds, etc. (See the
  screenshots web page.)

### Bug fixes and such:

- A longstanding bug: It was impossible to rename packets after opening
  them. Finally fixed, as part of a big string-operation cleanup.

- Another longstanding one, also part of the BSOC: On some platforms, when
  specifying a packet name on the command line, names of certain lengths
  wouldn't work. After I finally sorted this out, the surprising thing was
  that it had ever been working for names of any length. <sigh>

- Many potential buffer overflows and bogus limits fixed in the BSOC. Others
  remain. :-(

- Since time immemorial: When pulled from the address book into a message,
  the "To:" field was being restricted to 29 characters, regardless of packet
  type. Also, the length of names in the address book had been limited to 44
  characters.

- A fresh one: Reply packets were being stamped with a bogus date.

- The packet list, if sorted by time, is no longer rearranged when a packet
  is Touched.

- Replies are now preserved in the event of a crash during the write-out
  process. Inspired by Matt Munson.

- The highlight bar wasn't showing up in XCurses -- probably since about
  version 0.18, which shows how often I try that port. (I also had some
  other problems with XCurses, as yet unsolved; it sometimes locked up on
  starting.)

- Stupid bug in SOUP: segfault on message areas with 8-character filenames.

- The line showing "BBS:" and "Sysop name:" in the area list is now omitted
  if neither is defined (as in SOUP packets), leaving an extra line for the
  areas themselves.

- The minimum screen size is now 60x17. I'm shooting for 40 columns. ;-)

## 0.38 - 2001/02/03:

### New features:

- First new version in over seven months! See, it's not dead after all.

- Transparency: There are three new keywords in the .mmailrc which are
  mainly for making the background transparent, for use in programs like
  Eterm which can put an image in the background: "UseColors" (default:
  yes), "Transparency" (default: no), and "BackFill". "Transparency" only
  works in ncurses; "BackFill" is the only one available on all platforms.
  See the man page for more on these.

- New date/timestamp handling: When updating packets with the .red markers,
  MultiMail now preserves the original timestamp of the file. This means
  that date sorting will reflect the order in which packets arrived, rather
  than the order in which they were last read. (Note, however, that this
  feature doesn't quite work correctly in the Win32 port (see README.win).
  One way around this would be to use PKZIP with the "-k" option; or just
  use the DOS port.) Inspired by Ingo Brueckl. At first I had this toggled
  by a keyword, but then...

- The complement to the new timestamp handling is the 'T' function in the
  packet window, which "Touches" a file, setting its timestamp to the
  current time. I needed this because I actually depend on the timestamps
  being updated sometimes.

- New "ExpertMode" option suppresses the help text, for those who are
  familiar with the commands and would rather use more of the screen for
  text. Four lines are gained in the packet, area and letter lists, among
  other gains.

- In a related note, you now can gain seven lines in the packet list by
  undefining VANITY_PLATE in config.h, but this is strictly a compile-time
  option. :-)

- OPX secretly restored. ;-)

### Bug fixes and such:

- Removed several older keywords to simplify the .mmailrc: BuildPersArea
  (even on my XT, it didn't really take much longer), MakeOldFlags,
  UseScrollBars, and AutoSaveRead (all these are now always on).

- The default editor for the Win32 port is now "start /w notepad". I'm not
  crazy about this, but under NT (in VMware), EDIT was completely locking
  up. Unfortunately MS provides no text-mode, native Win32 editor. (BTW, an
  interesting aside: Under NT, "notepad" is actually sufficient (the calling
  program waits for it to return); the "start /w" bit is for the benefit of
  9x, which otherwise launches notepad and returns immediately.)

- The Win32 port had trouble with the most recent Win32 version of PDCurses,
  because it now returns shift, alt and control immediately as keystrokes.
  (XCurses presumably had the same problem, but I didn't test this.) This is
  worked around now.

- SOUP (and BW v4): Newsgroup lines which exceed the width of the display
  now end in "..." to indicate a continuation. (You can see the entire
  "Newsgroups:" line by pressing 'X' for full headers.)

- SOUP (and BW v4?): Broken "References:" lines which contained no proper
  message ID's were causing segfaults. Reported by Peter Karlsson. BTW,
  would the perpetrators of these broken messages please fix them?

- SOUP: In 'm' mode, checking for "From "-line dividers is a little more
  rigorous; the line must now also contain an '@'. This eliminated all the
  false positives I was seeing on Pine-generated mail folders.

- In packets where the list of subscribed areas is not known (e.g., all
  plain QWK and SOUP packets), the "Subscribed" mode in the area list is now
  skipped automatically.

- The default color scheme is now a little less day-glo, :-) and shows up
  better on some terminals. The old one is still available in tradit.col.
  Let me know what you think.

- Ncurses' built-in SIGWINCH handler is on by default in 5.0+; this was
  conflicting with MultiMail's handler. It should now work OK, but see
  NCURSES_SIGWINCH in interfac.h if you're not using ncurses' defaults.

- When going backwards through messages via '-' and backing out of an area,
  the display was not updated correctly. I've also changed the behavior of
  '-' in this instance to go back to the last non-empty group instead of the
  last group (more consistent with '+').

## 0.37 - 2000/06/28:

### New features:

- Moved web site and email from ClarkNet to SourceForge. Among other
  benefits, this means that old versions of the MultiMail source code are
  now archived online, going back to 0.1. Binaries (for certain platforms)
  from 0.36 on will also be archived.

- New compression type: tar/gz. (New .mmailrc keywords: "tarCompressCommand"
  and "tarUncompressCommand".) Unlike the other types, this recompresses the
  entire packet when updating the .red flags, so it can be a bit slow. Also,
  the supplied command lines assume GNU tar, which has gzip built-in.
  Separated gunzip/tar and tar/gzip command lines would require a (simple)
  external script. MultiMail only checks for the gzip signature. Requested
  by Peter Karlsson for compatibility with GNUS.

### Bug fixes and such:

- The packet list could crash on directory names longer than 32 characters.
  Reported by Tuukka Lehtinen.

- Zero-length messages caused a segfault. Reported by T.L.

- In SOUP packets with index files, the .idx file would be opened instead of
  the corresponding .msg file. Reported (indirectly) by Peter Karlsson.

- GNUS apparently uses a bogus identifier 'n' in the first position of the
  attribute fields of the AREA files in the SOUP packets it generates,
  equivalent to the standard type 'u'. MultiMail now recognizes this flag.
  Reported by P.K.

- In MakeChain(), rejoin is now always applied to non-quoted lines. This
  looks better in most cases; in particular, where space padding on the end
  of a line resulted in a line of exactly 80 columns. (Previous versions of
  MultiMail would print an extra blank line then.)

- relist() is now always called from MakeActive() in the area list and
  little area list. This means that the list is updated properly in Active
  mode, among other things.

- In the packet list search function, the wrong packet was highlighted.

- On some platforms (including the NetBSD m68k binary distributed on the web
  site), forced word-alignment of structs broke the "old-style" (.PDQ-based)
  offline config in Blue Wave mode. (Yes, I should've anticipated this after
  the similar bug with OPX mode in 0.32.)

- The signature-adding routine will now skip CR characters, so (in
  principle) a .sig could be shared between Unix and DOSish readers. Other
  text files should still be kept separate. Inspired by Martin Prieto.

- The backslashes that had briefly appeared in the DOSish versions' packet
  windows had reverted to forward slashes again in 0.36. :-)

## 0.36 - 2000/04/28:

### New features:

- The area list has a new mode, "Active", to accompany the existing "All"
  and "Subscribed" views. The Active mode lists only those areas that
  contain messages. The L key now cycles among all three modes. (Note that
  in some cases, two modes may be equivalent; e.g., in plain QWK packets,
  there's no way to distinguish Active from Subscribed.)

- There's also a new "Marked" view in the letter list. If any messages in
  the area are marked, the L key cycles between all, unread, and marked
  views. (Otherwise, it toggles all/unread, as before.) Marked messages are
  no longer automatically included in the unread view.

- In the packet and letter lists, the current sort modes are now displayed.
  And in the area and letter lists, the current mode is displayed. The
  number of files is shown in the packet list, but only if the total number
  of items (files + directories) exceeds the window length. The area and
  letter lists now work similarly, showing the number of items only when
  they exceed the window length.

- By popular demand, the default modes for the area list (all, subscribed,
  or active) and the letter list (all or unread) can now be set in .mmailrc.
  See the "AreaMode" and "LetterMode" keywords.

- Old-style Blue Wave offline config, using .PDQ files, is now supported.
  (.UPI/.NET replies still aren't, yet.) Requested by Russell Tiedt.

- Specifying a directory on the command line now opens the packet window on
  that directory. No more items are read from the command line afterwards.

- In Unix, the "~" character is now recognized as a synonym for the contents
  of the "HOME" environment variable in input, and is also used that way in
  the packet list display. (However, "~username" is not supported.)

- The Tab key works as an alternative to Enter in input windows.

- The BCC port is now the "standard" Win32 port. (The RSX/NT port is still
  available, renamed mmrsxNNN.zip.)

- New BeOS binary.

### Bug fixes and such:

- Makefile.tcc and Makefile.bcc are now sensible -- no more renaming or
  moving kludges. :-) Also, the "UNUSED_PARAMS" nonsense is gone, and
  MultiMail compiles without warnings under BCC.

- The message and ansi viewers can now handle > 64k in the 16-bit version,
  depending on available memory.

- In myreaddir(), the DJGPP, Turbo and Borland ports (mmdos, mmxt, and
  mmwin) now use findfirst()/findnext() instead of readdir()/stat(). This
  means that the packet window opens significantly faster on large
  directories. (stat() is fine in Unix, but slow in MS-DOS, where it's
  implemented via findfirst().) Also, the list is now built in a single
  pass, instead of one pass for files and another for directories, resulting
  in a speedup on all platforms.

- Test of read-only status now works in Borland/Turbo ports.

- Grabbing of Fidonet addresses was broken in some situations, causing
  segfaults. Reported by Greg Paski.

- When lines ended with spaces, they could be quoted incorrectly. Reported
  by Jim Hanoian.

- Tab characters in messages could cause segfaults in some cases.

- Soft CR stripping wasn't working.

- Looking through my (very) old packets, I found some in which another
  reader (?) had added its own files to a packet with the names "a0000.ndx"
  and "a0001.ndx", which made MultiMail generate a bogus area 0 for those
  packets. Fixed.

- The keypad mostly didn't work in the BCC (Win32) port of MultiMail.
  Reported by Jeff Foy.

- Using the Goto function in the packet list now puts the highlight bar on
  the first file, as when a directory is selected by pressing Enter. In Lynx
  mode, going left (back) in the packet list now actually goes to the
  previous directory, instead of the parent directory, and the previous
  highlight position is restored.

- When cycling through sort modes in the letter list, sort by "To:" is now
  skipped for areas which have no such field (i.e., Usenet areas).

- Wrapped header lines in SOUP are now displayed in the correct color.

- When writing out offline config (add/drop), the area list was scanned, but
  the current area number was not preserved. This sometimes led to minor
  cosmetic problems in the reply area. Reported by J.H.

- Finally replaced the ugly #define list in mmcolor.h with an enum.

- Some malformed Internet "From:" lines appear without a space between the
  name and address. In such cases, MultiMail was stripping the last letter
  of the real name.

- Several new error messages.

- The color files are now archived separately within the binary archives, to
  reduce clutter. Now if I can just figure out how to combine some of the
  documentation files in a sensible way...

## 0.35 - 2000/03/29:

### New features:

- None.

### Bug fixes and such:

- Oops! Due to the changes in the way LetterWindow::MakeChain() works, quote
  wrapping was broken. (Lines after wrapped lines would not be wrapped
  upwards, nor marked with quote marks.) A five-second fix, but alas, I
  didn't notice the bug until now.

## 0.34 - 2000/03/29:

### New features:

- Two new ports officially supported: An alternate Win32 port, via Borland
  C++ 5.5 (available free at the Borland web site); and, more interestingly,
  a 16-bit MS-DOS port, via Turbo C++ 3.0 (an ancestor of Borland C++ 5.5).
  I released an experimental version of the latter a couple weeks ago, but
  the official 0.34 version is much better, mainly in reducing memory usage
  and in not (always) giving up when memory runs out. :-)

- Areas that have replies are now always included in the short list, which
  prevents the replies being misdirected on re-edit. Such areas are also now
  flagged with an 'R' in the main area list.

### Bug fixes and such:

- The "References:" line disappeared from SOUP replies if they were
  re-edited before posting. Reported by J.B. Moreno.

- Massive reductions in memory usage for the LetterWindow and AnsiWindow
  classes. The plain message text takes up about half as much space as
  before; the ANSI viewer savings vary, but can be even greater.

- The environmental variable "TEMP" now works as an alternative to "TMP"
  with the DJGPP port. If neither of those is defined, nor "DJGPP", it will
  now use the startup directory instead of "C:\".

- TEMP or TMP values ending in a slash or backslash now work correctly in
  the Win32, OS/2 and 16-bit MS/DOS ports. Also, all these ports now use the
  startup directory rather than the MMAIL directory as the default location
  for the temporary directories and files, in the absence of a TEMP or TMP
  environment variable.

- SOUP replies sometimes had the wrong length in the length field (one byte
  too long), resulting in spurious characters at the ends of messages.

- Skip trying to add to read-only files. (But this check doesn't work yet in
  the Borland/Turbo ports.)

- References to "interface" in the code changed to "ui". (Apparently,
  "interface" is a reserved word in Borland C++.)

- Soft CR stripping moved to the Blue Wave class. Let me know if this is a
  problem. (I haven't seen them in QWK or OMEN packets, and they'll never
  appear in SOUP.)

- Various code cleanup. Now 16-bit clean, among other things. :-)

## 0.33 - 2000/02/21:

### New features:

- Support for encoding and decoding Quoted-Printable headers and bodies,
  primarily in SOUP packets. Decoding is always performed; encoding is
  performed subject to the new .mmailrc keywords "outCharSet", "UseQPHead",
  "UseQPMailHead", "UseQPNewsHead", "UseQPMail" and "UseQPNews". Thanks to
  Peter Karlsson for some of the code.

- Support for the OPX format has been removed. I hope this will be only
  temporary. The reason is not technical. If you're affected by this, and
  you'd like to continue using OPX, please email me privately.

- Support for individual packet types may now be disabled when compiling, in
  order to save a little space in the executable. The packet modules to
  include are selected in the "modules" file.

- The Rename function in the packet list now brings up a Blue Wave-style
  default filename, with a numeric extension based on the last one found
  plus one, unless the packet already has a numeric extension. Also, rename
  failures are reported, and you can no longer rename to the name of an
  existing file.

- Some extra pop-up notices like "Opening...", mainly for the benefit of
  slower systems. :-) There are also additional non-fatal error messages in
  several places, as when a Save fails.

- .XTI support is now fully segregated into the Blue Wave module. This is
  cleaner, but it means that .XTI files are only recognized in Blue Wave
  packets, and not in other types. The default for the "MakeOldFlags" option
  in .mmailrc has been changed to "Yes".

- The automatic prefixing of "Re: " on the subjects of replies can now be
  disabled, for non-Internet areas only, via the "ReOnReplies:" .mmailrc
  keyword. By popular demand. :-)

- New color scheme contributed by Tuukka Lehtinen.

- Before the removal of the OPX module, these features were added:

- In OPX mode, MAIL.FDX is now handled in the same way as .XTI in Blue Wave
  mode. It's written instead of .red when "MakeOldFlags" is set.

- Offline config in OPX mode. Thanks to Armando Ramos for the format.

### Bug fixes and such:

- "To:" and "From:" kludge lines in text are now checked only in QWKE
  packets, instead of all QWK packets. This should help with some systems
  that require "To:" lines for Internet addressing.

- Blue Wave anonymous areas are now recognized as alias areas, as in QWKE.

- Areas flagged as read-only will no longer accept replies, and will pop up
  an error box instead. This works in Blue Wave, QWKE, and OMEN. Requested
  by Jaakko Lintula.

- The MS-DOS version sometimes segfaulted due to bugs in DJGPP's qsort().
  Fixed by upgrading to a newer DJGPP library. Reported by Laird Kelly.

- When reading the .mmailrc file, unrecognized keywords are now reported.
  May help to catch typos. :-)

- In OMEN mode, when the UserName was not set in .mmailrc, all messages were
  being flagged as personal.

- Defaults for "AutoSaveReplies" and "AutoSaveRead" changed to "Yes".

- Compiling on an Alpha revealed several bugs that didn't show up on systems
  where pointers and ints were the same size (i.e., all the 32-bit systems);
  mainly inappropriate usage of resource::get() vs. ::getInt(). MultiMail is
  now 64-bit ready. :-) Thanks to Compaq for the free account.

- In Blue Wave mode, the echotag field is now used as the area description
  if the description field was left blank. Problem reported by Greg Mayman.

- Internet address parsing modified to deal with badly-formed addresses like
  "(Name) <address>". Problem reported by Dane Beko.

- There were intermittent segfaults in the letter window with screens wider
  than 80 columns, due to an off-by-one error in memory allocation.

- The following fixes were made to the OPX module prior to its removal:

- Some versions of the Silver Xpress door eat the last character of the tear
  line. MultiMail now pads it out with a sacrificial space in OPX mode.
  Reported by Jim Hanoian.

- Some OPX packets split their areas into BRDINFO.DAT and EXTAREAS.DAT;
  MultiMail should now be able to handle this (untested). Reported by
  Armando Ramos.

- On some platforms (e.g., the NetBSD version distributed on my site), OPX
  support was not working due to structure alignment padding. Fixed.

- New line ending recognized: plain CR. (This is in addition to the LF,
  CRLF, and 0x8D endings recognized in 0.32.) If you got messages with blank
  bodies, or immediate segfaults when opening messages, this will probably
  fix it. Reported by Laird Kelly.

- Certain packets (with messages over 64k?) reportedly had incorrect values
  in the length fields of some messages, causing everything after that point
  to become unreadable. This is fixable by using MAIL.FDX to index the
  messages, which MultiMail now does. Reported by Armando Ramos.

## 0.32 - 1999/10/30:

### New features:

- Support for the OPX packet format. This was reverse-engineered, and has
  really only been tested with the WINS door. See mmail/opxstrct.h in the
  source code archive for the specs.

- A "Personal" area (messages addressed to you) is now created automatically
  for all packet types except SOUP. This can be turned on or off (default is
  on) via the "BuildPersArea" option in the .mmailrc -- except in QWK
  packets with .NDX files, where the presence or absence of a "personal.ndx"
  file determines whether the area is generated (the same as in older
  versions of MultiMail).

- With Blue Wave packets (and _only_ with Blue Wave packets), MultiMail now
  has the option (off by default) of storing its last-read pointers in an
  ".xti" file, as used by the Blue Wave reader and some compatible programs
  (like BWSave), instead of in MultiMail's native ".red" format. This is
  toggled by the "MakeOldFlags" option in the .mmailrc. (I made the name
  generic in anticipation of support for other such formats, like OPX's
  "mail.fdx".) In reading, .red no longer takes precedence over .xti; if
  both files are present, the one with the later date is used.

### Bug fixes and such:

- Character set translation now works correctly on Linux text consoles that
  use Unicode-mapped fonts. Problem reported by Peter Karlsson. Also, OMEN
  replies to Latin-1 packets were not recognized as being Latin-1 on
  rereading; initial printing of translated fields in the header editor was
  incorrect; and the ANSI viewer always assumed CP437.

- Forwarded messages now add only the changed header lines to the body of
  the text, instead of using the same format as saved messages.

- Date in SOUP replies was being localized, which is undesirable. Reported
  by P.K.

- The Personal area now always shows the correct number of unread messages
  in the area list.

- Blank lines are now added automatically before signatures, and the sigdash
  ("-- ") in Internet and Usenet areas is correctly followed by a newline
  before a sig. (Previously, it worked right with taglines, but not sigs.)

- Areas with a very long description could cause a segfault when opening the
  letter list. (They were truncated, but not quite enough since the addition
  of the message count.) Also, the header of the letter list now takes
  advantage of the full width of larger screens.

- Can now read net-status QWK packets correctly, even without .NDX files.
  (End users shouldn't really be reading net-status QWK packets; but judging
  by a packet I was sent, some are.)

- Empty subject lines are now forced to the end of the letter list when
  sorting by subject, instead of messing up the sorting as they were doing.

- Precautionary fix for hypothetical corrupted Y2K date fields in Blue Wave
  packets. Hopefully not needed. :-)

- The User-Agent line in SOUP mode now includes "SOUP" in the comment. :-)

## 0.31 - 1999/10/07:

### New features:

- When a new version is run for the first time, instead of prompting whether
  to continue or quit, it prompts whether to edit the .mmailrc file or just
  continue. Should save a step. ;-)

### Bug fixes and such:

- Text files (e.g., MMAIL.RC, or the DOOR.ID or CONTROL.DAT from a QWK
  packet) which did not end in a line feed character would cause MultiMail
  to lock up. This was due to a new line-reading function introduced in
  version 0.30, which fixed some other problems, but stupidly added this
  one. Due to the seriousness of this bug, I'm releasing 0.31 early.
  Reported by David Pratt et al.

- Searching did not work in the little area list. (This dates to 0.29,
  though I just noticed it.)

- In SOUP packets, extra spaces between header keywords and values are now
  ignored.

## 0.30 - 1999/09/30:

### New features:

- Support for SOUP packets. Note that type 'M' areas and index files are not
  supported yet; only 'm', 'b' and 'B'.

- Support for OMEN packets.

- The new keywords "UserName" and "InetAddr" are used to build a default
  "From:" line for SOUP replies, of the form "UserName <InetAddr>". If you
  leave them blank, no "From:" line will be generated. (Conforming SOUP
  packers, like UQWK, will generate their own "From:" lines in that case.)
  The UserName is also used in OMEN mode for display purposes (the actual
  From name is set on upload), and for matching personal messages.

- Replies in Usenet areas may now be cross-posted; the newsgroups list can
  be edited.

- Quote headers can now be set in the config file (separately for Internet/
  Usenet areas, and others), via the "QuoteHead" and "InetQuote" keywords.
  The maximum width for quoted material can also be set, via "QuoteWrapCols"
  (suggested by Holger Granholm). See the man page for details.

- The "Lines:" indicator now includes a percentage.

### Bug fixes and such:

- Long lines in text files would sometimes cause the remainder of the file
  to be read incorrectly. Mainly, this could show up with the tagline file.
  Reported by Dane Beko. Also, blank lines in the tagline file are now
  ignored.

- Area 0, if present, was not being sorted in the letter list.

- In the MS-DOS version, the first shell-out would trash the old prompt, so
  second and subsequent shells had a bogus prompt. Reported by Jerel
  Arbaugh.

- When re-editing a reply and shortening it, the remaining text could end up
  off the screen when returning from the editor. Reported by Jim Hanoian.
  Also, a similar effect could be briefly seen when editing a reply from the
  original, if the reply was shorter.

- Text entry fields did not work correctly when backspacing if the text
  filled the field. Reported by Tom Rutherford.

- Changed default zip commands -- removed "-o" (for both PKZIP and InfoZip)
  and added "-k" for InfoZip. The latter option forces stored pathnames to
  an MS-DOS compatible 8.3 unicase format, which ensures maximal
  compatibility with doors and such. You may want to add this yourself if
  you're upgrading; but note that it could result in two ".red" files being
  stored into packets that had been read without this option.

- Saved messages can now have longer header lines, and the headers are more
  appropriate (closer to what you see in the letter window) for Internet/
  Usenet areas.

- Signatures and/or tearlines in Internet/Usenet replies are now prefaced
  with "-- ", and "... " is omitted. Signatures are recognized in text in
  these areas, are colored with the tagline color (I'll make this a separate
  color later), and are not quoted when replying.

- Long subject lines and other long lines can now be fully edited,
  regardless of screen width, and will be fully displayed if the screen is
  wide enough.

- In Internet/Usenet areas in Blue Wave packets, the subject, date and
  newsgroups are now extracted from the kludge lines in the text, as with
  references and message-id. (Most of the changes in this version of
  MultiMail are for enhanced Internet/Usenet support; although this was
  primarily for the benefit of SOUP, it carries over into Blue Wave.)

- TAB characters are now decoded into spaces in MakeChain(). This prevents
  them from pushing lines off the screen. But to save a message with its TAB
  characters intact, you have to save it from the ANSI viewer.

- Strip any number of leading "Re:"'s, not just the first.

- Filenames within reply packets are now created in upper case, even if you
  don't use the "-k" option (see above). Mainly this was for compatibility
  with the MBSE BBS, though there may be others with the same problem. (The
  format specs generally show the filenames in upper case, so this is
  arguably the correct behavior for a case-sensitive filesystem; but most
  were designed with the FAT filesystem in mind, and only SOUP explicitly
  addresses the issue of case.)

- "Re: " will not be prepended if it would make the subject exceed the
  maximum width for the format. Also, non-QWKE QWK packets now have their
  subjects limited to 25 characters (again); the "Subject:" kludge will not
  be added except in QWKE packets. (I'll add it back for some later, when I
  can identify the particular door's capabilities better.)

- ':' and '|' are now recognized as quote indicators, but only when
  appearing in the first column. (But if ':' is the start of a smiley, it's
  ignored.)

- When quoting in Internet/Usenet areas, blank lines now have a quote marker
  prepended, as this seems to be the standard.

- Intitial check for 80x20 instead of 60x20, error if screen too small.

- I made a (temporary) patch to PDCurses for the MS-DOS version, so that
  MultiMail will work correctly in non-standard video modes. Problem
  reported by J.A.

- Overdue documentation of the .mmailrc file in the man page.

## 0.29 - 1999/08/29:

### New features:

- List windows now have a "scroll bar" when the number of items in the list
  exceeds the number that will fit onscreen. This feature is selectable via
  the "UseScrollBars" keyword in .mmailrc (on by default). Note that it's
  not (yet) mouseable.

- The new "UseLynxNav" option (off by default) changes the function of the
  left and right cursor keys: left backs out, and right selects. (It's named
  after the Lynx web browser. The idea comes from Pine, which has a similar
  option.) It also makes the left arrow equivalent to selecting ".." in the
  packet list, except on the top level (where it's equivalent to Quit).

- Fido "SEEN-BY:" lines are now marked as hidden if they weren't already.
  (This allows you to turn on the "extended info" option in Blue Wave doors
  below ver. 4 with impunity.)

- The Delete key will work as an alias for 'K' in all cases.

### Bug fixes and such:

- Major bug: In certain cases, the little area list would not set the
  correct area, and the reply would be misdirected. Reported by Jerel D.
  Arbaugh.

- Outside of the packet/area/letter list, the search routine could abort in
  some cases (i.e., '/' would simply not work). Reported by Jim Hanoian.

- If a message was saved (from the letter list) before any messages had been
  viewed, it could be saved rot13'd!

- The "soft CR" filter was not working if the console character set was
  Latin-1.

- Re-editing of replies from the original area could move the letter list
  selection inappropriately (to the corresponding reply number).

- If the last-opened packet was deleted and replaced by another packet of
  the same name, the old packet would be "reopened" even though it was gone.
  Reported by Raymond Cool.

- Lines which contained a '^A' character, but _not_ at the beginning of the
  line, were erroneously being marked as hidden.

- "Re:" is now left visible in the letter window, though still stripped from
  the letter list. (In this, I emulate Tin.)

- During a search, the beep-on-personal would beep on each personal message
  scanned, even when the corresponding message was not actually displayed.

- When shelling out, the prompt string could be truncated if it was
  excessively long. Not really a bug -- I just hadn't believed that anyone
  would actually have a prompt string that long. :-) Reported by J.D.A.

- Due to its placement at the start of a line, an instance of the word
  ".mmailrc" was interpreted as a control code and disappeared from the
  formatted man page. Reported by Geoffrey Wilson.

## 0.28 - 1999/07/28:

### New features:

- Offline config! (Add/Drop only, at the moment.) For Blue Wave, QWKE, and
  QWK (with DOOR.ID indicating Add/Drop support). See the man page for
  details.

- The area list window now has additional status flags: '+' and '-' for
  added/dropped, and '*' in the full list for subscribed areas. The little
  area list has '*' also, and is now wider.

- A more advanced search routine. It will now (optionally) descend levels,
  allowing even a full text search over multiple packets.

- The address book now allows direct entry, as well as editing of existing
  addresses. The tagline window allows editing of existing taglines. (The
  old function of the 'E' key in the tagline window has been moved to the
  'A' key.)

- Reply splitting, both manual and (optionally) automatic.

- Quick exit from any screen via ^X.

- Command shell (for DOSish ports) via ^Z.

- Packets can now be specified directly on the command line, bypassing the
  packet menu. (If multiple packets are listed, they will be opened in
  sequence.)

- Better quote wrapping -- paragraphs are rewrapped, and second-level quotes
  are not requoted (except in Internet/Usenet areas, which use a reduced
  quote for second-level quotes).

- Optional stripping of "soft carriage returns" (those annoying accented i's
  that sometimes appear).

- Optional beep in letter window when opening personal messages.

### Bug fixes and such:

- The "Yes/No" prompt to keep old reply packets has been replaced by
  "Save/Kill", to reduce the chances of deleting a packet by mistake (as can
  happen when one is in the habit of hitting 'N' in response to the new
  files or bulletins prompts). Suggested by several users.

- In all string input windows (those that use ShadowedWin::getstring()), a
  backspace as the first character will now preserve the default text (if
  any). I'm not sure if it's better this way or not, though.

- The tagline window was displayed improperly on a screen wider than 80
  columns when scrolled up or down a line at a time.

- I've changed the message MultiMail shows the first time a new version is
  run, to something I hope is clearer. Please note that MultiMail will never
  wipe out the values from your old config file, only update the file with
  new keywords (if any).

- When changing to a new directory (or on startup), the first file rather
  than the first directory is highlighted.

- When composing a new message and not quoting, MultiMail no longer creates
  a 0-byte temp file before launching the editor. (You probably won't notice
  the difference, but I think it may address one bug report I got a while
  back. For me, it makes pico say "New file" instead of "Read 0 line".)

- Some more egcs warnings fixed. (Odd; they should have appeared earlier.)

- Internal reorganization: Most non-ANSI, non-curses code is now in
  mysystem.cc. I hope this may simplify porting to non-POSIX systems. Also,
  part of interfac.cc was split off into basic.cc; and some stupid #define
  and const int lists were replaced with enums.

## 0.27 - 1999/06/27:

### New features:

- The little area list now has short-list capability, like the main area
  list. Press 'L' to toggle it.

### Bug fixes and such:

- In QWK reply packets, the binary conference number was not being included.
  This made them incompatible with some doors (at least some versions of
  Galacticomm's software, and probably EzyBBS). The problem goes back to
  MultiMail's beginnings. I didn't notice it before now because most QWK
  doors use the ASCII conference number instead. (There are redundant fields
  in a REP packet.) Thanks to SparkAm@peyam.net for tracing the problem.

- The precompiled MS-DOS binary of 0.26 wouldn't work on machines without
  FPUs, due to the FPU code linked in with the difftime() function in the
  packet list. I've replaced this with an integral subtraction, which is
  adequate for my purposes. Reported by Greg Mayman et al.

- curs_set() is now called from Win::cursor_on() and Win::cursor_off(),
  regardless of the curses implementation. (Formerly, these lines were
  ifdef'ed.) This is for compatibility with ncurses 5.0-beta1, which no
  longer calls it from leaveok(). I'm told that Solaris curses doesn't,
  either.

- A netmail address on a message would be retained if the message were
  forwarded to a non-netmail area, and it would not be editable. Reported by
  Jim Hanoian.

- The packet list window length is now variable for lists shorter than the
  max, as with the letter list. The "info" window in the area list has been
  merged into the main window. (The visible effect of this is that the lower
  window no longer has a title.)

- Some internal reorganization.

## 0.26 - 1999/05/26:

### New features:

- Automatic saving of replies is now available via the "AutoSaveReplies"
  keyword in .mmailrc. When this is enabled, MultiMail automatically
  rewrites the reply packet after a reply is created, edited or killed. It's
  similar to pressing "F2" or "!" after each event, but without the warning
  window. I'm considering making this the default behavior for future
  versions -- any comments?

- The "AutoSaveRead" keyword turns on automatic saving of the last read
  markers when exiting a packet, bypassing the "Save lastread" prompt. (This
  is another thing I might make the default.)

- Packets may now be renamed from the packet list window by pressing 'R'.
  (This function can also be used to move them to different directories,
  though you must specify the filename as well as the pathname of the
  destination.)

- Directories are now shown in the packet list, and are navigable; or you
  can specify a directory to jump to via the 'G' command. (On the DOSish
  ports, the 'G' command is the only way to change drive letters.) The
  current directory appears as the title of the packet list window. Note
  that this change means that the old behavior of exiting when no packets
  were found will effectively never occur.

- By popular request, multiple replies to the same message (in the same
  reply packet) are now allowed. (This is a partial reversal of the change
  in 0.24.) When re-replying, you're prompted to re-edit; if you say no, a
  new reply is generated. Only the first of the existing replies will be
  recognized for re-editing.

- When opening a packet, you're now prompted whether or not to keep any
  existing replies.

- The tagline window can now be completely disabled via the "UseTaglines"
  keyword in .mmailrc. Requested by Jack Pfisterer.

### Bug fixes and such:

- Re-editing replies from the reply area no longer forces a return to the
  letter list. Instead, the re-edited letter is displayed.

- Cosmetic problems with the wrong area being displayed on the status line
  (and the header window) during the reply process have been cleared up.

- The "This will overwrite any existing reply packet" warning from the F2
  function is now suppressed if there is no packet.

- MultiMail will now display a warning if the reply packet is not created,
  or if the last read markers could not be saved. Also, it will pause for
  two seconds after getting an error code from a program it shelled to
  (archiver or editor) or attempted to shell to, so that any console error
  messages from the system may (hopefully) be read.

- Speculative fix for reported problems with replies disappearing (which I
  couldn't reproduce): calls to clearDirectory() now pass the name of the
  working directory explicitly, rather than ".".

- Added "-e" to the default add command for ARJ to suppress pathname
  inclusion. Suggested by Ken Whiton.

- The separate colors for the Search window have been eliminated, as the
  Save dialog is now used for both (as well as for the new prompts in the
  packet list).

- The "F2, !: Make reply packet" function is now available in the letter
  list and letter window, as well as the area window.

- Shorter date format in the packet list; more space for long filenames.

- On Blue Wave messages with no taglines, a blank line is now inserted
  before the origin line.

- Fixed errors (and some warnings besides) that made MultiMail 0.25
  incompatible with egcs. Thanks to Tony Summerfelt for reporting the
  problems and testing (and re-testing) the solutions.

- If there was a tagline in the message on screen, and you chose not to use
  a tagline in the reply, the tagline from the original would be used
  instead. Reported by David Toutant and J.F. (With the reorganized tagline
  code, I've also reverted to having the tagline grabber pick the last
  tagline in a message, instead of the first.)

- In Blue Wave mode, when the packet filename differed from the "base name"
  (BBS id), the former was used for replies, when it should be the latter.
  Reported by Jim Hanoian.

- After animating ANSI, MultiMail would loop on a non-blocking keyboard
  check, sucking up CPU.

- As usual, lots of internal reorganization.

## 0.25 - 1999/03/19:

### New features:

- Support for Internet and Usenet messages in Blue Wave mode. (Note: AFAIK,
  this is only supported by the Blue Wave version 4 door for PCBoard.) Also,
  Internet addresses can now be taken into the address book.

- Character sets (either code page 437 or Latin-1) are now selected for each
  area or message. The default character set is CP437 (as before), except
  for Internet or Usenet areas (as marked by Blue Wave or QWKE flags), which
  are Latin-1. The character set in individual Fidonet messages can be
  overridden by the "CHRS:" or "CHARSET:" kludges. Replies are set according
  to the default for the destination area.

- The console character set and the default sort types for the packet and
  letter lists can now be set in the config file. The default packet sort is
  now by time (latest first) instead of by name.

- The "To" field is now omitted from the letter list in Usenet areas and the
  QWK Personal area. The "From" field is omitted in the REPLY area. This
  leaves more room for the "Subject" lines by eliminating redundant info.

- Direct support for RAR archives. Note: there's a problem with this if you
  read the same packets in, e.g., both Linux and DOS: RAR will save the last
  read marker file twice (once in upper case, once in lower).

- More ANSI navigation: The ENTER key now works the same in the ANSI viewer
  as in the letter window (advance to next message).

- The packet list can now be rescanned (to pick up new packets) by pressing
  'U'.

- The message count now appears in the title bar of the letter list (like
  the area count in the area list).

- New color scheme by Gary Gilmore.

### Bug fixes and such:

- The alternate QWK private message flag, '+', was not being recognized.
  Reported by Tom Rutherford.

- Changed the message that prompts to save replies to something I hope is
  clearer. Suggested by Max Chamberlain.

- If the reply packet had a different archive type than the main packet,
  MultiMail would attempt to use *that* archiver (the reply packet's) to add
  the last-read markers to the main packet. The correct behavior is to use
  the main packet's archive type when remaking the reply packet!

- When quoted material was wrapped, the wrapped lines would have trailing
  spaces. These are now stripped.

- In the area and tagline lists, a completely blank line would sometimes
  appear at the top of the list. (A long-standing bug, finally fixed.)

- Strip blank lines after hidden lines. (Blue Wave puts blanks after the
  hidden headers in Usenet messages.)

- Fewer keys to hit in the header editor. :-) The cursor is now placed on
  either the Subject or To line, as appropriate (you can still arrow up to
  edit the other lines); and the "Make message private?" prompt is not
  presented when sending to areas that are either all-public or all-private
  (as indicated by Blue Wave or QWKE flags).

- Bizarre alignment bug in the EMX-based ports (OS/2 and Win32) caused
  crashes on some QWK packets. Reported by Jim Hanoian.

- Source code reorganized somewhat... no more .a files.

- Blue Wave packets could have identical areanums in multiple areas.
  Although this is an error, the Blue Wave reader handled it; now MultiMail
  does as well. This is also a little faster. However, it assumes that the
  mixRecords and INF area headers are sorted the same way, which I would've
  preferred not to assume. Problem reported by Scott Jones.

- In 0.24, the new packet kill routine failed to exit after killing the last
  packet, leaving garbage on screen. Reported by Gary Gilmore.

- A filename without an extension would mess up the display in the packet
  list. A long-standing bug that I never really cared about, but which J.H.
  mentioned.

- All directories are now omitted from the packet list.

- One more attempted cursor fix for the Win32 version.

- Minor display bug with messages 100,000 lines or longer. (Now OK up to
  1,000,000.)

- In the EMX ports, in the letter sort by subject, the secondary sort by
  message number was still broken. Reported by J.H.

## 0.24 - 1999/02/12:

### New features:

- "Save" function in ANSI mode. This differs from the letter window save in
  that no wrapping is performed, and no header is prepended. This is also
  the only way to save bulletins and new file lists.

- New navigation in ANSI mode: the space bar and left and right arrow keys
  now work in the same way as in the letter window. This also means the
  interface for the bulletin viewer is slightly different: 'Q' exits from
  the entire list, instead of just the current bulletin, and you can move
  back and forth between bulletins as in the letter window.

- Multiple sort modes in the packet list: by date (latest first), and by
  name. By name is still the default. "$" toggles between them.

- Multiple sort modes in the letter list: by subject (still the default),
  message number (i.e., no sort), from, or to. "$" cycles through them.

- The help window at the bottom of the packet, area and letter lists can now
  show multiple pages of options (similar to Pine's "Other commands" menu
  function).

- When character set translation is on in the ANSI viewer, some IBM
  characters are now mapped to curses equivalents, giving a better result on
  non-PC terminals (e.g., xterm, vt100). This works best with the box-
  drawing characters. The letter window still uses a plain ASCII mapping for
  these characters.

- Pop-up help is now available in the ANSI viewer, as in the letter window.

- Messages can be forwarded from any area, with the original headers
  preserved in the text.

- Support for the Win32 console via RSX/NT. See README.rsx if you want to
  compile for this platform.

- Fidonet MSGID/REPLY kludge lines are now supported, in Blue Wave mode.

- Additional QWKE support -- in QWKE packets, the short list now shows
  "subscribed-to" conferences, as in Blue Wave mode, instead of just the
  non-empty ones; and alias areas are supported. The "QWKE" type appears in
  the Info window of the area list.

- When Replying to a message that's already marked "Replied", the previous
  reply (if available) will be re-edited instead of a new reply being
  created.

- Some new color schemes.

### Bug fixes and such:

- The help window now survives a screen resize, instead of being closed.

- Killing a packet no longer forces a reread of the directory.

- The addressbook will no longer grab a new entry when no Fido address is
  available. Also, the addresses are now sorted alphabetically on startup.
  (Anything added during the session will not be alphabetized; however, the
  list will be sorted again on the next startup.)

- The full length of Blue Wave "To" and "From" fields is now available in
  the header editor. (Previously, they were restricted to 25 characters.)

- The subject sort in the letter list was not correctly performing the
  secondary sort, by message number, in runs of the same subject.

- Time/date printout code changed in packet list and in Blue Wave reply
  headers. I think this looks a bit better.

- The experimental Win32 console version had a problem with slow screen
  output. This seems to be a problem with the console API (?), but it's
  worked around in this version. (Normally, PDCurses checks for a keypress
  after printing each line. In Win32, this call takes a noticeable amount
  of time to return, even though it's supposed to be non-blocking. So, in
  MultiMail, the check is disabled for the Win32 version. This also disables
  typeahead, but I doubt anyone will even notice that.)

- A last attempt at fixing the remaining cursor problems in the PDCurses
  versions. (The cursor size is now checked at startup, and that value is
  explictly restored instead of using curs_set(1).) Scott Jones reported the
  persiting problem in the OS/2 version.

- The index of the Personal area is now updated just by entering the letter
  list, or anytime a message is read in that area. Better than previous
  versions, though still not ideal.

- Support for the keypad plus, minus, and slash keys under PDCurses. (This
  completes the keypad "Enter" fix in the previous version.)

- The experimental Win32 version supported only "\" in the pathnames
  specified in MMAIL.RC, where the DOS and OS/2 versions allowed either "\"
  or "/". Now both work in Win32, and both will be converted to "\" when
  MMAIL.RC is updated. Reported by Rafael Cresci.

- One more character allowed for unames in Blue Wave reply packets (six
  instead of five). Specifically, that means "MultiMail/MS-DOS" and
  "MultiMail/NetBSD" will now appear in Blue Wave tearlines, instead of the
  abbreviated form "MultiMail".

- Hidden lines at the end of a message would cause the line count to be over
  by one. Reported by Jim Hanoian.

- In the Save dialog, user-entered names were getting spaces converted to
  underscores, though only the second time through (when the name was pulled
  up as the default). Reported by J.H.

## 0.23 - 1999/01/22:

### New features:

- QWKE and PCBoard-style "Subject:", "To:", and "From:" line kludges are now
  supported in QWK mode, along with "Title:", which is used on WWIV. The
  QWKE "Subject:" line is generated automatically for replies, if needed.
  Note that in regular messages (though not in replies), these lines aren't
  parsed until the message body is accessed by entering the letter window,
  so the fields as shown in the letter list will at first be the short
  forms.

- Reply forwarding -- press \<CTRL\>-'F' while in the reply area (either the
  letter list or letter window) to forward a reply. (Forwarding of regular
  messages is not available yet.)

- In the REPLY area, 'R' now works as an alias for 'E'. Added at the
  insistence of Jim Hanoian. :-)

- When (re-)editing or forwarding a reply, the area can now be changed.

- REPLY and PERSONAL areas now show the original area (as well as the
  collection area) in the letter window. Suggested by J.H.

### Bug fixes and such:

- New behavior in the ANSI viewer: Instead of resetting everything when a
  screen-clearing code (<ESC>[2J) is encountered, it sets the last-drawn
  line as the new baseline, and continues from there. With the old system,
  information was sometimes lost (though it could still be viewed in the
  animation mode); now, screens are simply chained together, and everything
  is visible and scrollable.

- Characters 8 (backspace) and 12 (form feed) are now handled in the ANSI
  viewer, and skipped in the letter window. Ctrl-Z is stripped in the ANSI
  viewer.

- The BBS name and Sysop name fields in the info window of the area list
  were being unnecessarily truncated.

- In the PDCurses versions, the cursor remained disabled when shelling to an
  editor. Reported by Dane Beko. (Due to the way I implemented this fix,
  PDCurses 2.2 is no longer acceptable for MultiMail; you must use 2.3.)

- When creating a .REP, a zero-length message body would cause a segfault.

- Blank space at the end of the little area list is now omitted (as in the
  letter list).

- An attempt to send Netmail when no Netmail area is defined (as is always
  the case in QWK mode) now pops up a nonFatalError window.

- The "Save lastread pointers?" message now comes up less often; the "any
  read" flag is set less aggressively. (If you re-read a message that's
  already marked as read, the any-read flag will not be set, as it was in
  previous versions.)

- When entering areas which are fully read, the highlight bar is no longer
  moved to the last message. Similarly, if the entire packet is marked as
  read, the active area is not set to the last non-empty area, but the
  first. Suggested by J.H.

- Hopefully, a better subject-line sort in the letter list: If two subjects
  have the same content for the entire length of the shorter of the two, the
  shorter one is no longer automatically placed first; instead, they're put
  in message number order.

- The ENTER key on the numeric keypad did not work in the PDCurses versions.
  Reported by Russell Tiedt.

- Added "/m" to the parameters passed to LHA in the MSDOS version. Without
  this, it gave an "Extension is not .lha. Continue? [Y/N]" prompt when
  archiving replies.

## 0.22 - 1999/01/01:

### New features:

- The long-awaited support for new file lists and bulletins! They're
  displayed automatically on opening the packet. Currently, this is a bit of
  a kludge -- although I'm starting to like it. Memory usage is excessive.
  (See the man page for more info.)

- Support for XCurses (the X port of PDCurses). See README.xc for details.

- Added a line counter to the ANSI window, as in the letter window.

### Bug fixes and such:

- If a tagline was displayed on screen, it would replace the tagline
  selected for a reply via the tagline editor. This bug dates to 0.20.

- TAB characters that advanced past the end of a line were causing problems
  in the ANSI viewer.

- Aborting a netmail reply left the netmail address set when a regular reply
  was attempted afterwards.

- The translation toggle ('c') now works in all screens. (In particular, the
  ANSI viewer.)

- Proper printing of character 127 (DEL) under ncurses.

- The SIGWINCH (resize) handler now works acceptably even when a SIGWINCH
  occurs while in a WarningWindow() or getstring() call.

## 0.21 - 1998/12/15:

### New features:

- Not new, but newly documented: When run under Windows 95, the MSDOS
  version supports long filenames! Apparently this is a feature of the DJGPP
  standard library, though I didn't realize it before. (I don't know about
  Win 98 or NT -- anybody else?)

### Bug fixes and such:

- The code to generate the default tagline file was broken in 0.20, which
  meant that all first-time users got a segfault. Argh! Also, since I was
  messing with the taglines anyway, I changed the default list.

- In the PDCurses versions, the "Could not uncompress packet" and "Packet
  type not recognized" messages would pop up without first restoring the
  packet list screen. Also, some extra parentheses have been added around
  color names for the benefit of PDCurses/Win32 (still an incomplete port).

- Updated the README.{DOS,OS2} files to reflect the new style of default
  MMAIL.RC in use since 0.19.

- "/" and "." added to pop-up help window.

## 0.20 - 1998/12/06:

### New features:

- Search function. Case-insensitve searching is available everywhere. It's
  still a bit limited, in that it only works within the current list (or
  letter); i.e., you can't yet search multiple letters at once. Hit '/' to
  bring up the text entry window and start the search, or '.' to repeat the
  last search. (Yeah, I know -- it needs better keys.) Searching is from the
  current line on down.

- Fido "hidden" message lines (marked with a ^A) can be displayed; 'X'
  toggles this function.

- New features in the tagline editor and address book: New entries in the
  address book are checked for dupes; also, tagline dupes, which were
  already checked, are now reported. The address book and the tagline editor
  allow you to Kill entries. And the tagline editor can be brought up
  directly, via ^T, in the same way as the address book. Old features: The
  reLoad function has been removed from the tagline editor.

- Rot13 function in letter window -- toggle with 'D'.

- If a new letter is not edited (as measured by the time stamp), you'll be
  asked if you want to cancel it on returning to MultiMail. Partly inspired
  by Gregory Paksi.

- Redundant colors can be omitted from the ColorFile. See colors/README.col
  for details. Also, there are some new colors, and some old ones are gone;
  be sure to check your ColorFile if you've customized it.

- Messages to or from you are highlighted in a different color in the letter
  list. After Ingo Brueckl (though this implementation is a little different
  from his).

- Read-only support for Blue Wave's .XTI files (last-read markers). This
  means that any old packets you read with Blue Wave will be marked in the
  same way when first opened in MultiMail; however, any changes made in
  MultiMail will not be seen by Blue Wave. Partly inspired by I.B., but this
  is a different (and more correct) implementation.

- "Home" and "End" keys are now available in text entry fields (i.e.,
  ShadowedWin::getstring()). After I.B.

### Bug fixes and such:

- The FMPT kludge line is now supported, which means that in Blue Wave mode,
  the netmail addresses of points will be recognized.

- Aborting a header edit from the letter list could cause a segfault. (The
  fix in 0.19 was incomplete.)

- Some bogus ANSI codes (mainly, "ESC[?7h") are now semi-interpreted, so
  they no longer clutter the screen. Also, the ANSI background color is now
  hardwired to white on black, instead of being set by Main_Back.

- The highlight method for the active line was no good on a light background
  with ncurses 4.2 (was ok with 4.1). Some other changes for light
  backgrounds, too.

- High-bit, "low-bit" (below 32) and certain special characters are now
  handled better by MultiMail, being actually printed instead of interpreted
  as control codes. :-) Particularly useful for ANSI.

- TAB characters are now rendered as the appropriate number of spaces in the
  letter and ANSI windows.

- In text entry fields (getstring()), high-bit characters were showing up
  with weird attributes (due to a sign error). Reported (indirectly) by
  I.B., this bug has been present since about 0.10! I'm suprised no one from
  Fido zone 2 mentioned it to me before.

- Packets can now be renamed without MultiMail losing track of its last read
  markers. (This will, however, still result in a second .red file being
  created.)

- When entering a tagline manually via "E" in the tagline editor, the
  entry field is now placed correctly, instead of appearing to overwrite the
  last tagline. Also, bogus taglines are no longer generated from message
  lines which are just "...".

- In the Reply area, the help menu for the letter list was showing a 'K'
  where it should've been an 'S'. Also, capitalization in help menus has
  been standardized (only the keys that activate commands are in caps in the
  descriptive text), and the pop-up letter help window is now in two
  columns.

- Killing an item (in any menu) now moves down to the next entry, regardless
  of the position in the list (unless at the end).

- The 'L' command now remains available in the address book after a screen
  resize (SIGWINCH). Also, taking an address via 'L' automatically sets the
  active line to the last position (where the new entry is).

- Netmail addresses are now included in Saved letters.

- The resize (SIGWINCH) handler was causing a segfault in some
  circumstances. Although I just noticed it, this bug dates to 0.18.
  Curiously, it occurred for me only when running under "screen". The fix
  was to change Win::inkey() to remove the loop.

- Changed the .mmailrc separators from " = " back to ": ", which makes
  them compatible with 0.18 and earlier. I'll probably change them again. (I
  was trying to achieve a more "classic" style of .rc file, but in fact,
  it still wasn't quite right.)

- The cursor was not being disabled in PDCurses versions.

- "Read" indicator in the letter window was not updated after Saving.

- Changed interface/Makefile and mmail/Makefile to allow "make clean" to
  work in DOS. Suggested by I.B.

- And of course, various internal changes.

## 0.19 - 1998/10/25:

### New features:

- The .mmailrc has been redesigned. New versions of MultiMail will update it
  automatically; comments will be lost, but old data will be preseved. Note:
  the new form is not readable by 0.18 or earlier, because of the use of '='
  as a separator. Partly inspired by Ingo Brueckl.

- Non-fatal errors. Currently, this is used only for the previously fatal
  "Could not uncompress packet" and "Packet type not recognized".

- You can change the colors MultiMail uses without recompiling. See the
  automatically generated "~/colors" for details; also, some sample color
  schemes are included in the 0.19 archive. This feature is due largely to
  Ingo Brueckl.

- "Marked" messages are kept in the active letter list, whether read or
  unread. In combination with the "Save" changes (see below), this means
  that marking is now actually useful. :-)

- Extensive changes to the "Save" dialog: When you Save from the letter
  list, you're given a choice of "All", "This one", or "Quit"; if any
  messages are marked, you also get the option "Marked". Saving "All"
  now saves all messages in the active list, rather than all in the area.
  (To get the old behavior, just toggle the full list on first.) Saving a
  message sets the "Read" flag, and turns off "Marked". The last-entered
  filename is retained (separately) for "All", "This One", and
  "Marked". If no name is entered manually, the automatic name is
  regenerated with each use; otherwise, the manual name is kept until you
  exit MultiMail.

### Bug fixes and such:

- Segfaults in saving All, in some cases.

- Certain ANSI pics, with codes in the form "<ESC>[;27H" (i.e., with
  an empty parameter before a semicolon) were causing segfaults.

- After the cursor was turned on, e.g. by the Save window or an aborted
  message header edit, it was left in the middle of the screen on some
  terminals. It is now forced down to the corner.

- The header editor was being left on screen after exiting via ESC.

- Removed the text "Fatal Error" from fatal errors. :-) It was sometimes
  redundant, and other times wrong.

- When the last packet was deleted from the packet list, a segfault could
  occur. Reported by Alan Ianson.

- Functions which redrew the letter window (e.g., toggling character set
  translation) were setting the Read marker each time.

- The tagline window now looks better on screens other than 80 columns.

- Various internal changes, and added comments.

## 0.18 - 1998/08/14:

### New features:

- MultiMail can now read QWK packets without .NDX files. Partly inspired by
  Simon Callan. Note: It's still preferable to include them, since it takes
  about three times longer to open the packet without them. (But that's not
  counting the unpacking time, which is much longer still.)

- The letter list now allows toggling between showing all messages, and
  showing only those which are unread; when entering an area, it defaults to
  unread (unless all the messages are marked read). I've found that this
  makes a BIG difference in the feel of the program -- it's more like a
  newsreader now. ;-) Use the 'L' key to toggle between the long and short
  lists (as in the area list).

### Bug fixes and such:

- Removed a lot of redundant code from the interface section, and
  reorganized it... There are many new features that need implementing, but
  so far I've been concentrating on cleaning up and simplifying the existing
  code, so as to have a solid base to build on. I think I'm almost there.
  ;-)

- Found a couple small memory leaks, in AnsiWindow (the statbar was not
  being deleted) and main_read_class. Also, the tagline file was being left
  open after reading it.

- Now gives a fatal error (instead of segfaulting) if the screen is smaller
  than 60x20.

- The address book and tagline window now respond correctly to SIGWINCH.

- In the tagline window, the key for rereading the file has been changed
  from 'F' to 'L'. This allows 'F' to be used as an alias for PgDn, as on
  other screens. (The real purpose was to merge the code into the rest of
  the keyboard-handling code.)

- If there was only one area (i.e., REPLY), and the right arrow was pressed,
  an infinite loop would occur. Reported by Tamminen Eero.

- The 'N' key, for Netmail, is now disabled when no Netmail area is
  available. Partly inspired by Francois Thunus.

- Sample filenames in the default .mmailrc now conform to the OS (i.e., 8.3
  (FAT) format for DOS and OS/2), and the unused "ReadDir" line has been
  removed. Inspired by F.T.

- Stripping and adding of blank lines at the end of messages works a little
  better now, but still needs work.

- The addressbook was crashing, when empty (0 items). Reported by Marc D.
  Williams.

## 0.17 - 1998/07/06:

### New features:

- Netmail addresses, when present in Blue Wave packets (or reply packets),
  are displayed in the From: or To: fields in the letter window, as
  appropriate; and when entering a netmail message, the address can now be
  edited. (Note: Netmail is largely untested yet.)

- In the header editor (From, To, etc.), you can now use the up and down
  arrows to move between fields, or press ESC in any field to abort the
  edit. Press ENTER on the last field to exit normally.

- Reading a message in the QWK Personal area marks it as read in its
  original area.

- A full area list is now available in both QWK and Blue Wave modes; it can
  be toggled by pressing 'L' in the area list. (The compile-time
  "shortlist" definition has been removed.) One benefit is that you can
  enter a message in any area, even when only the short list is being
  displayed.

- When re-editing a message, you can now edit the header as well as the
  text.

- ANSI animation. While in the ANSI viewer, press one of the ANSI activation
  keys again (or 'A') to see an animated view. Press any key to abort the
  animation.

- The ANSI viewer supports the screen-clearing code.

- The cursor is turned off, wherever possible. Less visual clutter. :-)

- True scrolling instead of redrawing; minimized the redrawing done for
  letter window, ANSI viewer, and all ListWindows. It's now MUCH faster on
  slow machines and slow terminals.

### Bug fixes and such:

- MASSIVE rewrite... Almost everything that was crufty in previous versions
  is now done the right way. :-) General fixes include: plugging memory
  leaks (there were a lot of these, I'm sorry to say), elimination of
  one-based arrays, adding more limit checks, and removal of all kinds of
  kludges and redundant code. The interface is more fully separate from the
  specific drivers; adding new packet types now requires changing only
  mmail/driverl.cc.

- The netmail area is found by attribute rather than name, and (owing to the
  full area list now available in Blue Wave mode) can always be found,
  instead of only when you have received netmail. :-)

- Character set translation is applied to the area list, and to area
  descriptions in the letter list and letter window.

- The number of replies shown in the REPLY area is updated immediately when
  it changes.

- The method of adding blanks before taglines and tearlines is changed; it
  should no longer be necessary to type an extra CR at the end of replies.

- QWK replies are automatically word-wrapped at 80 columns, if they're not
  wrapped already. (In Blue Wave, this is not desirable. QWK doors seem to
  prefer individual lines; Blue Wave, paragraphs.)

- MultiMail now ensures that QWK replies end with a line-ending character,
  instead of letting the last line run off into the padding area. Without
  this, certain QWK doors would strip off the tearline.

- The path is no longer displayed in the Save window, and the suggested
  filename is conformed to FAT (8.3) standards. Note that you can still
  enter any pathname, and any filename that will be accepted by your system.

- Specifying pathnames that end in a slash or backslash (e.g., in .mmailrc)
  should now work correctly.

- The extraneous "bw" prefix found on many of the .mmailrc variable names
  is no longer needed, though it will still be recognized for backwards
  compatibility.

- Space bar now works in the little area list.

- The QWK "Personal" area no longer appears in the little area list, nor
  can messages be entered in it from the area list.

- Unrecognized packets no longer cause a segfault (just an exit).

- Added trivial SIGWINCH handlers for AddressBook and TaglineWindow (they
  just exit that menu).

- Fatal errors are now reported correctly in the OS/2 version, even when
  they occur before curses initialization.

- In the ANSI viewer, there are no more segfaults in OS/2, and no more stray
  characters on the status line in either PDCurses version.

- ANSI Reverse attribute now works with PDCurses.

- ANSI viewing works in reply area.

- A SIGWINCH can no longer result in the active (highlighted) line being
  displaced off the screen.

- New default LHA parameters for MSDOS version (the Unix ones didn't work
  for it).

- The currently selected address is preserved between calls to the
  AddressBook.

## 0.16 - 1998/05/28:

### New features:

- This version compiles for OS/2, with EMX. This entailed substantial
  changes to the Makefile (q.v.), as well as some code.

- The environment variable MMAIL can now be used instead of HOME, to specify
  the directory of the .mmailrc (or mmail.rc) file. If neither variable is
  defined, MultiMail will use the current directory (this is also new).

- The DOS-to-Latin 1 character table has been improved, for translation of
  graphics characters, by stealing most of the table from DOSEmu.

- Truly automatic packet recognition, by packet contents instead of name.
  Patch by Robert Vukovic.

- Internal ANSI viewer. Works on all platforms (except that it sometimes
  segfaults when scrolling, under OS/2). Much better than the "less"
  viewer, and it will form the basis of new file list and bulletin
  viewers.

### Bug fixes and such:

- Another big bug in the DOS version (argh!): Last read markers were not
  being saved. This bug was the result of an error in the bug fix in 0.15.
  :-/ I'm surprised no one has reported this.

- In the previous DOS versions, under some arrangements of directories, the
  temporary directories would not be removed.

- The man page has been renamed to "mm.1", and the title changed, so that
  "man" and "apropos" will work more appropriately. The install will
  make a link to the old name (mmail.1).

- The "Replied" flag is now set by O- and N-type replies, as well as R.

- Some code reorganization.

## 0.15 - 1998/05/12:

### New feature:

- If you back out from a packet, to the packet list, you can now reselect
  the same packet without it being decompressed again. Thanks to Robert
  Vukovic for convincing me of the need for something like this.

### Bug fix:

- In DOS, the default editor (edit.com) didn't actually work, because it
  didn't understand paths with slashes instead of backslashes. I missed this
  because it worked with Qedit. :-) The slashes are now flipped on the
  pathnames passed to external editors and archivers (in DOS only). Thanks
  to kifox@geocities.com for reporting the problem.

## 0.14 - 1998/04/25:

### Bug fix:

- A more subtle line-ending bug... under MSDOS, extra characters were
  sometimes added to the end of a reply. (Unix versions were not
  affected.)

## 0.13 - 1998/04/24:

### Bug fix:

- While making changes to accomodate MSDOS line endings, I made a small
  oversight that caused replies to be truncated at one character if they
  were re-edited.

## 0.12 - 1998/04/23:

### New features:

- Compatible with MSDOS. All source code files have been changed to
  single-case, 8.3 form, and #ifdef's are used on filenames internally where
  necessary. (Most other issues are taken care of by DJGPP, though some
  Makefile changes were necessary, and the starting directory is now
  restored on termination -- needed in DOS, but not in Unix.)

- Compatible with PDCurses (as distributed with DJGPP), and SysV curses
  (specifically, Solaris). Note that the shadows on windows are opaque if
  you compile with SysV curses. (I also added "#define USE_SHADOWS", which
  you can comment out or remove to get rid of the shadows
  altogether.)

### Bug fixes and such:

- After the reorganization of resource.C in version 0.11 (if not before),
  any change to the value of mmHomeDir in .mmailrc would leave the
  bwPacketDir, bwReplyDir, etc. variables unaffacted.

- memError() now works correctly, even before initialization of the
  interface. Fatal errors in general will be reported better in this
  version.

- Some additonal bounds checking on sprintf() calls.

- tmpnam() checked. In principle, as few as 26 temporary filenames might be
  available from it (which should still be enough, unless you write a whole
  lot of replies).

## 0.11 - 1998/03/21:

### New features:

- Area and system descriptions added to saved messages.

- I removed the last remaining command-line option, "-m", on the grounds
  that it was useless. (This is a new UNfeature.) After testing it on my
  9600 bps terminal, it doesn't appear to improve the speed; and the
  alternate color scheme, which it was originally designed to select, was
  never implemented. (Instead, I've added inversing to the top and bottom
  bars in the letter window, and made a few other changes to make it more
  monochrome-friendly.)

### Bug fixes and such:

- resource.C and resource.h rewritten and simplified to allow compilation
  with gcc 2.8.1. (It's not yet clear to me why the old version didn't work,
  but this is better anyway.) There are still a few warnings, but it works
  OK.

- When entering the From:, To:, and Subject: on replies, the full width of
  the fields had not been available. Under some circumstances, this could
  even cause a segfault. These lengths still need to be checked more
  stringently.

- Automatic "Re:" adding now takes place before subject-line editing,
  instead of after. This allows users to see that it will be added, and to
  override it if desired. (It also saves a few bytes of code!) I don't know
  why I did it the other way before.

- In the event of a "Fatal Error:" exit, MultiMail will now clean up after
  itself, as with normal exits. Also, failed memory allocation is now
  explicitly checked.

- Default paths for "zip" and "unzip" removed. (These would only show up
  if the paths were not defined in the .mmailrc -- as they are with the
  default .mmailrc.) Thanks to Carey Bloodworth for pointing this out.

- If the message numbers exceeded 5 digits (i.e., 100000+), they would mess
  up the display in the letter list. Now, it takes 6. :-)

- Much internal reorganization.

- Fixed a bug with my website -- the new-style URL (/~wmcbrine/) messed up
  some relative pathnames. :-)

## 0.10 - 1998/03/07:

### New features:

- Shadowed windows! Tell me if you like them.

- SIGWINCH support. You can now resize the terminal (e.g., maximize the
  xterm) while MultiMail is running, and it will adapt to the new
  size.

### Bug fixes and such:

- Under Solaris, the help menu area was not being cleared when changing from
  one menu to another.

- One more space available in letter list (now consistent with the other
  lists).

- On some systems (such as Linux w/ glibc, and NetBSD), if you attempted to
  read a packet that didn't already have a "bbsid.red" file (mm's read
  markers) in it, MultiMail v0.9 would segfault right after unzipping a
  packet, due to a very stupid attempt to call fclose() with a NULL pointer.
  Under Linux w/ libc.5, this actually worked OK; and I didn't notice it on
  my NetBSD test system because the packets there already had .red files in
  them. Thanks again to Cesar Cardoso for reporting the problem.

  Due to the seriousness of this bug, I'm releasing v0.10 early.

## 0.9 - 1998/02/26:

### New features:

- Added alias, "!", for F2. Added Tab as an alias for right arrow (next
  unread) in letter list.

- Better handling of screen widths other than 80; better use of available
  screen space even in 80 columns. Still to do: handle SIGWINCH.

- QWK now has the option (on by default) to show only those areas which have
  messages in them, instead of the full area list. I set this on by default
  to match the behavior of the Blue Wave side; you can change this in the
  top-level Makefile. Currently, it's only a compile-time option. (In the
  future, I'll add the ability to do a full list in Blue Wave mode, and to
  toggle the mode at runtime.)

- .REP and .NEW filenames are now forced to lowercase. Should be easier to
  type. :-) But if you have any uppercase-named reply packets from previous
  versions, you'll have to manually rename them before 0.9 will recognize
  them. Sorry.

- Blue Wave mode now works on big-endian systems! The full functionality of
  MultiMail is now available on all platforms where it compiles. And
  "-fpack-struct" is no longer needed in the Makefile -- which I hope may
  mean increased portability.

- system() calls to rm and sed have been eliminated.

### Bug fixes and such:

- Strip spaces from Blue Wave subject lines; fixes sorting in some cases.

- In Blue Wave mode, MultiMail was using LF as a paragraph delimiter. The
  correct behavior is to use CR as the delimiter and ignore any LFs. Thanks
  to Marc D. Williams for submitting a packet that required this fix.

- Messages in Blue Wave packets are supposed to have a leading space, but
  packets produced by the ReneWave door lacked them. They also contained
  nulls in messages (a no-no). MultiMail now deals with these problems
  without flaking out. Thanks again to M.D.W.

- With Blue Wave packets, MultiMail now scans for "*.inf", instead of
  assuming that the packet name minus the extension is the basename.
  Normally, that is the case, but the "welcome!.000" packet that comes
  with the Blue Wave reader -- which uses "welcome" internally -- is a
  counterexample. MultiMail can now read this packet. :-)

- Startup for QWK packets is much faster, especially on slow systems.
  Previous versions would attempt to open the .ndx file for each area
  defined in the control.dat (and would do so several times for each area),
  whether it existed or not; 0.9 scans to see which .ndx files actually
  exist first.

- Changed ANSI viewer to work better with certain messages. Really, I should
  make it user-definable, instead of being hard-wired to "less"; but I'm
  probably going to make it into an internal function anyway.

- Added "#include <sys/types.h>" to mmail/mmail.h. Usually I wouldn't
  mention a change of this type, but in this case, it was done to get
  MultiMail to compile with glibc (libc 6). Thanks to Cesar Cardoso for
  reporting the problem and testing the solution.

- Saved messages are now wrapped at 80 columns, regardless of screen width
  at the time of saving; and the date is now added to the saved header.

- Replying to a message no longer messes up the right margin of the original
  when viewing it immediately after replying.

- Paths are no longer stored with the .red file when using LHA. In previous
  versions, this could cause the storing of multiple .red files into a
  packet.

- Next/previous unread in letter list now work correctly, even with messages
  that have manually been marked Unread.

- Miscellaneous minor internal fixes and optimizations.

## 0.8 - 1998/02/10:

### New features:

- "Re: " is stripped from subject lines, for sorting and display purposes,
  and added automatically on replies (unless doing so would truncate the
  subject). Subject sorting is now case-insensitive.

- Letter window now displays "bbsnum (x of y)", for consistency with the
  letter list and to provide more information.

- Slightly expanded the area description length to make better use of the
  available space. Also, in the letter list, more of the subject is shown.

- Restored the "line/lines" counter found in early versions of MultiMail.
  This shows the length of the message in lines, and the number of the top
  line on screen.

- Temporary files are now cleared at the end of a session. Also, since
  MultiMail now generates a unique temporary directory for each session, a
  single user can run multiple concurrent sessions. (Just don't try to read
  the same packet in each one!)

- System uname added to Blue Wave tearline (if it will fit).

- Character set translation can now be toggled at runtime, by pressing 'c',
  instead of at compilation time.

- Packet type is now recognized automatically, based on the filename's
  extension. (You can still force the other type.) Consequently, the "-b"
  and "-q" options have been removed.

- The Blue Wave area list now uses the description instead of the echotag.
  This is much more useful, and conforms to the Blue Wave reader.

- The number of the original message is now passed to the door for reply
  linking.

- In the letter window, the top and bottom bars are now inversed when in
  monochrome. In the various lists, the highlight bar is now drawn with
  stdout(), for greater contrast.

- Many changes to the top-level Makefile; it's now more portable, and
  commented. You can now set the location of the ncurses header file here,
  instead of editing the source.

- The packet list is now sorted, and shows file sizes as well as dates.

- The backquote character (`) is converted to an ESC when using the ANSI
  viewer. (Some systems recode ESC characters this way.)

- You can now Kill packets from the packet list.

### Bug fixes and such:

- If all preexisting replies were deleted, attempting to create a new reply
  during the same session could cause a segfault.

- Terminal newlines stripped from replies. Conforms to the Blue Wave reader;
  suppresses gaps after the tagline with some doors.

- QWK subject fields had been truncated at 24 characters. (The field is 25
  chars.)

- The tagline file can now be hand-edited without introducing blank lines.

- In the letter window, PgDn, End, and the down arrow now stop at the actual
  end of the text.

- No more extra junk in Blue Wave reply packets.

- Blue Wave replies can now be safely reedited. (Previously, the line
  endings could be messed up -- left in Unix format.) Stray characters no
  longer appear at the end of Blue Wave replies while viewing them.

- Blue Wave mode, like QWK mode, now shows the BBS message numbers in the
  letter list, instead of the messages' position in the packet.

- Trailing ", Sysop" stripped from sysop name in QWK mode.

- Opening reply packets that were generated by the Blue Wave reader caused a
  segfault, due to case mismatch; it now works correctly.

- Version number "encryption" for Blue Wave replies fixed (so the number
  appears correctly in tearlines). (IMO, the Blue Wave specs are in error in
  describing this feature -- bluewave.h refers to addition when it should
  say subtraction.)

- Left and right arrow keys in the area list now work much faster when
  skipping empty areas, and can take you to the first and last areas,
  instead of second and next-to-last.

- Killed the stupid repeating-REPLY-area bug in Blue Wave mode.

- When creating Blue Wave replies, MultiMail now makes the proper choice
  between "real name" and "alias", depending on the area flags.

## 0.7 - 1997/12/07:

### New features:

- Right and left arrow keys now select next/previous unread message in an
  area, similarly to the way they function in the area list (jumping to
  non-empty areas).

- ANSI viewer. Hit ^A while reading a message to view it in color, if it has
  ANSI codes embedded. This is still rudimentary; it uses "less" as the
  viewer, and it depends on the terminal to interpret the codes.

- Private flag support. Complete, except for Blue Wave area flag checks.

- Character set translation is essentially complete. The only further
  changes I envision are the ability to turn translation on or off at run
  time, instead of at compile time; some possible changes to the translation
  table; and maybe additional character sets.

- Stolen taglines are checked for dupes, included only once.

- With some minor changes, I got it to work under SunOS (Solaris). No longer
  just a Linux program! :-) So, the tearline is now derived from the uname.
  Blue Wave mode still requires a little-endian system.

- QWK "Personal" conference.

- Many key aliases added, mainly for use on terminals that don't support
  keys like PgDn and F1. Also, Space Bar now functions as a combination
  PgDn/Enter in the letter window, to allow paging through a conference.

- Marking and read/unread toggle now work from the letter list, simplifying
  bulk marking. In the REPLY area, Kill now works from the letter list.

- Automatic creation of .mmailrc and the mmail directories; no more "make
  install_dirs".

- Changed bluewave.h to version 3. (No related feature changes yet.) I now
  use it in unmodified form; "-fpack-struct" is sufficient.

### Bug fixes and such:

- Suppression of "hidden" text lines added for Blue Wave (already present
  for QWK).

- Append saved files instead of overwrite.

- If saving without a path specified, save in the "save" directory.

- Better adaptation to nonstandard screen sizes.

- Really random taglines (previously, there was no call to srand).

- "Save lastread pointers?" and "Reply area has changed..." messages now
  come up only when appropriate.

- "Personal" column in area list removed in QWK mode. Maybe not a bug, but
  it was unused.

- Fall back to login name if no alias name defined. (It was using only the
  alias name, sometimes leading to blank From: lines in Blue Wave mode. This
  feature needs more work -- the alias should not always be the default.)

- Various date fixes (QWK and Blue Wave).

- Print the right area type for QWK Replies.

- Area names padded out with spaces when necessary to correct a cosmetic
  defect in the REPLIES/PERSONAL letter lists' "Area" fields.

- Version number references made consistent.

- Remove extra bytes from ends of messages (QWK and Blue Wave).

- A big one: Kill the *correct* reply messages with 'K'. (!)

- A BIG one: QWK reply area numbers fixed. It was using the internal area
  number, rather than the QWK number; so replies would go to the wrong
  areas! (Under specific conditions -- a packet with conferences that were
  numbered serially, starting from zero -- this would actually work right,
  which is doubtless how the bug snuck in to begin with.)

- Stop truncating replies. (This bug complimented the extra byte bug,
  preventing segfaults in the old version.)

- I changed the default directories from "bwdown", etc., to "down", etc.
  This wasn't a bug, but it was too Blue Wave-centric for a dual-function
  reader. (I believe the original intent of K.T. & T.I. was that the QWK
  implementation would have its own directories, e.g., "qwkdown";  but as
  implemented by J.Z., a common directory was used. I may revert to the
  putative original design at some point. Internally, the "bw"  prefix is
  still used on many shared structures.)

- Make .REP packets from the BBSID, not the base packetname.

- "Unread" now counts all messages marked unread, not just those which are
  also unmarked and unreplied.

- Letter sort fixed (now sorts by number within each subject), and faster.

- Eliminated the defaulting to "reply" when an otherwise undefined key was
  pressed.

- Calls to todos replaced with internal code.

- QWK .ndx parser replaced with faster, non-endian-dependent version.

- Many ncurses changes. Most importantly, shells and (normal) exits now
  restore the screen mode. (Error exits still need fixing.)

- Makefile changes (including centralizing options in top-level Makefile).
  Could do with a bit more changing, I think.

- A big one (since it prevented me from even using 0.6, as it was): Fixed
  segfaults on opening packets with uppercase names within (i.e., those from
  most or all DOS-based BBSes).

- Many minor changes to suppress warning messages during compilation.

- Many, many more. :-) These are just the user-visible ones.

### Bugs unfixed:

- The lockup-on-exit bug, described below as having appeared in 0.3 and
  disappeared in 0.4, has resurfaced. I too am unable to trace it. It can
  come or go after almost any random change in the code.

-- William McBrine

## 0.6a - 1997/03/25:

- Oops! The signature was in the wrong place. Right order is: signature,
  tagline, tearline ;-)

- Tagline adoption is supported! (Doesn't check dupe tags yet.)

- QWK-reply packs contained '\n' as a line terminator. It's incorrect! We
  have to use softCR (char#227).

- Character conversion is somewhat in! For ISO 8859-1 <--> CP437 (DOS)
  translation, #define ISOCONVERT in /interface/interface.h

- ISO conversion doesn't do the from/to/subj yet

## 0.5a - 1997/03/22:

- Fixed another date bug (when reloading QWK replies, the date would be
  mangled).

- You can now use a signature file after each letter (specify its filename
  in .mmailrc)

- Says error, if ~/.mmailrc isn't found. (The program needs this file!)

- File open errors printed, inside a BW/QWK packet, it tries four variations
  of the filename (eg. mybbs.dat, MYBBS.dat, MYBBS.DAT, mybbs.DAT).

- The annoying bug, which occurred when quitting, has disappeared!
  ;-o

## 0.4a - 1997/03/12:

- Fixed the date handling with QWK packets. Should do it well. That part
  wasn't even implemented before.

- Colors should be fine now, everywhere.

- One small, but ANNOYING bug introduced: the program doesn't exit properly,
  sometimes you have to kill it! Sorry, couldn't trace this bug yet. Maybe
  you can help.

## 0.3alpha - 1997/02/16:

- Took out many more bugs. This version now is almost usable ;)

- You can now (re)Edit your reply!

- Major design and color changes... Still not done, but doing good!

- Added message Marking, Read/Unread toggle.

## 0.2alpha - 1997/02/12:

- Debugged the program, fixed lots'a bugs, added QWK support. Only a
  preview! Don't use it, that's my advice! ;)

-- John Zero

## 0.1c.staticbin - 1996/??/??:

- statically linked elf executable of 0.1c. Problems were reported with gcc
  2.7.2 and libc 5.2.?.

## 0.1c - 1996/03/19:

- bugfix, now uses "todos", instead of "/usr/bin/todos", only elf binary
  included

## 0.1b - 1996/02/05:

- Compiles on RedHat 2.1 + dynamic elf binary included

## 0.1a - 1996/02/03:

- INSTALL file created (cut from readme)

## 0.1 - 1996/01/27:

- initial release

-- Kolossvary Tamas and Toth Istvan
