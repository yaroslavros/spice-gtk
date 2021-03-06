/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2010 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SPICE_UTIL_PRIV_H
#define SPICE_UTIL_PRIV_H

#include <glib.h>
#include "spice-util.h"

G_BEGIN_DECLS

#define UUID_FMT "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x"

gboolean spice_strv_contains(const GStrv strv, const gchar *str);
const gchar* spice_yes_no(gboolean value);
guint16 spice_make_scancode(guint scancode, gboolean release);
gchar* spice_unix2dos(const gchar *str, gssize len);
gchar* spice_dos2unix(const gchar *str, gssize len);
void spice_mono_edge_highlight(unsigned width, unsigned hight,
                               const guint8 *and, const guint8 *xor, guint8 *dest);

G_END_DECLS

#endif /* SPICE_UTIL_PRIV_H */
