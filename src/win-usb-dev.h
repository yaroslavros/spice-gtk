/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2012 Red Hat, Inc.

   Red Hat Authors:
   Arnon Gilboa <agilboa@redhat.com>
   Uri Lublin   <uril@redhat.com>

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
#ifndef __WIN_USB_DEV_H__
#define __WIN_USB_DEV_H__

#include <gio/gio.h>

G_BEGIN_DECLS

/* GUdevClient */

#define G_UDEV_TYPE_CLIENT         (g_udev_client_get_type())
#define G_UDEV_CLIENT(o)           (G_TYPE_CHECK_INSTANCE_CAST((o), G_UDEV_TYPE_CLIENT, GUdevClient))
#define G_UDEV_CLIENT_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), G_UDEV_TYPE_CLIENT, GUdevClientClass))
#define G_UDEV_IS_CLIENT(o)        (G_TYPE_CHECK_INSTANCE_TYPE((o), G_UDEV_TYPE_CLIENT))
#define G_UDEV_IS_CLIENT_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE((k), G_UDEV_TYPE_CLIENT))
#define G_UDEV_CLIENT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS((o), G_UDEV_TYPE_CLIENT, GUdevClientClass))

typedef struct _GUdevClient GUdevClient;
typedef struct _GUdevClientClass GUdevClientClass;
typedef struct _GUdevClientPrivate GUdevClientPrivate;

struct _GUdevClient
{
    GObject parent;

    GUdevClientPrivate *priv;
};

struct _GUdevClientClass
{
    GObjectClass parent_class;

    /* signals */
    void (*uevent)(GUdevClient *client, libusb_device *device, gboolean add);
};

GType g_udev_client_get_type(void) G_GNUC_CONST;
GUdevClient *g_udev_client_new(void);
libusb_context *g_udev_client_get_context(GUdevClient *client);
void g_udev_client_report_devices(GUdevClient *client);

GQuark g_udev_client_error_quark(void);
#define G_UDEV_CLIENT_ERROR g_udev_client_error_quark()

/**
 * GUdevClientError:
 * @G_UDEV_CLIENT_ERROR_FAILED: generic error code
 * @G_UDEV_CLIENT_LIBUSB_FAILED: a libusb call failed
 * @G_UDEV_CLIENT_WINAPI_FAILED: a winapi call failed
 *
 * Error codes returned by spice-client API.
 */
typedef enum
{
    G_UDEV_CLIENT_ERROR_FAILED = 1,
    G_UDEV_CLIENT_LIBUSB_FAILED,
    G_UDEV_CLIENT_WINAPI_FAILED
} GUdevClientError;


G_END_DECLS

#endif /* __WIN_USB_DEV_H__ */
