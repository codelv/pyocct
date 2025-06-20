/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2018 Keith Preston

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*

Dummy definitions of _xcolor and __GLXFBConfigRec

The OCCT include files for Linux use these two X Windows related structs.
Since pyOCCT doesn't need their internal details, it seems unnecessary to drag
in X library files, which may not be present in all systems anyway.

*/

#ifndef __xTypes_h__
#define __xTypes_h__

#if !defined(_WIN32) && !defined(__APPLE__)
// Includes X11/Xlib.h
#include <GL/glx.h>
#endif

#if defined(_WIN32)
#include "windows.h"
struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
    DWORD  lPrivate;
};
#endif

struct __GLXFBConfigRec {};

struct Aspect_XDisplay {};
struct Aspect_XVisualInfo {};



#endif /* !__xTypes_h */
