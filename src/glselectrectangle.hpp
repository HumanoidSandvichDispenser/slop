/* glselectrectangle.hpp: Handles creating hardware accelerated rectangles on the screen using X11 and OpenGL.
 *
 * Copyright (C) 2014: Dalton Nell, Slop Contributors (https://github.com/naelstrof/slop/graphs/contributors).
 *
 * This file is part of Slop.
 *
 * Slop is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Slop is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Slop.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IS_GL_SELECT_RECTANGLE_H_
#define IS_GL_SELECT_RECTANGLE_H_

#include "x.hpp"
#include "selectrectangle.hpp"

#include <unistd.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/extensions/Xrender.h>
#include <X11/Xutil.h>

#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

namespace slop {

class GLSelectRectangle: public SelectRectangle {
public:
                        GLSelectRectangle( int sx, int sy, int ex, int ey, int border, bool highlight, float r, float g, float b, float a );
                        ~GLSelectRectangle();
    void                setGeo( int x, int y, int w, int h );
    float               m_r;
    float               m_g;
    float               m_b;
    float               m_a;
    GLXFBConfig         m_fbconfig;
    XVisualInfo*        m_visual;
    XRenderPictFormat*  m_pictFormat;
    GLXContext          m_renderContext;
    GLXWindow           m_glxWindow;
    Colormap            m_cmap;
};

}

#endif // IS_GL_SELECT_RECTANGLE_H_
