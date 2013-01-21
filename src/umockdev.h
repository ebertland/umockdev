/* -*- Mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2012 Canonical Ltd.
 * Author: Martin Pitt <martin.pitt@ubuntu.com>
 *
 * umockdev is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * umockdev is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __UMOCKDEV_H__
#define __UMOCKDEV_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define UMOCKDEV_TYPE_TESTBED         (umockdev_testbed_get_type ())
#define UMOCKDEV_TESTBED(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), UMOCKDEV_TYPE_TESTBED, UMockdevTestbed))
#define UMOCKDEV_TESTBED_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), UMOCKDEV_TYPE_TESTBED, UMockdevTestbedClass))
#define UMOCKDEV_IS_TESTBED(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), UMOCKDEV_TYPE_TESTBED))
#define UMOCKDEV_IS_TESTBED_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), UMOCKDEV_TYPE_TESTBED))
#define UMOCKDEV_TESTBED_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), UMOCKDEV_TYPE_TESTBED, UMockdevTestbedClass))

typedef struct _UMockdevTestbed        UMockdevTestbed;
typedef struct _UMockdevTestbedClass   UMockdevTestbedClass;
typedef struct _UMockdevTestbedPrivate UMockdevTestbedPrivate;

GType         umockdev_testbed_get_type             (void) G_GNUC_CONST;
UMockdevTestbed *umockdev_testbed_new               (void);
const gchar  *umockdev_testbed_get_root_dir         (UMockdevTestbed *testbed);
const gchar  *umockdev_testbed_get_sys_dir          (UMockdevTestbed *testbed);
gchar        *umockdev_testbed_add_devicev          (UMockdevTestbed *testbed,
                                                     const gchar     *subsystem,
                                                     const gchar     *name,
                                                     const gchar     *parent,
                                                     const gchar    **attributes,
                                                     const gchar    **properties);
gchar        *umockdev_testbed_add_device           (UMockdevTestbed *testbed,
                                                     const gchar     *subsystem,
                                                     const gchar     *name,
                                                     const gchar     *parent,
                                                     ...);
void          umockdev_testbed_set_attribute        (UMockdevTestbed *testbed,
                                                     const gchar      *devpath,
                                                     const gchar      *name,
                                                     const gchar      *value);
void          umockdev_testbed_set_attribute_int    (UMockdevTestbed *testbed,
                                                     const gchar     *devpath,
                                                     const gchar     *name,
                                                     int              value);
void          umockdev_testbed_set_attribute_hex    (UMockdevTestbed *testbed,
                                                     const gchar     *devpath,
                                                     const gchar     *name,
                                                     unsigned         value);
void          umockdev_testbed_set_attribute_binary (UMockdevTestbed *testbed,
                                                     const gchar      *devpath,
                                                     const gchar      *name,
                                                     const gchar      *value,
                                                     gssize            value_len);
void          umockdev_testbed_set_property         (UMockdevTestbed *testbed,
                                                     const gchar      *devpath,
                                                     const gchar      *name,
                                                     const gchar      *value);
void          umockdev_testbed_set_property_int     (UMockdevTestbed *testbed,
                                                     const gchar     *devpath,
                                                     const gchar     *name,
                                                     int              value);
void          umockdev_testbed_set_property_hex     (UMockdevTestbed *testbed,
                                                     const gchar     *devpath,
                                                     const gchar     *name,
                                                     unsigned         value);
void          umockdev_testbed_uevent               (UMockdevTestbed *testbed,
                                                     const gchar      *devpath,
                                                     const gchar      *action);
gboolean      umockdev_testbed_add_from_string      (UMockdevTestbed *testbed,
                                                     const gchar      *data,
                                                     GError          **error);
/**
 * UMOCKDEV_ERROR:
 *
 * Error domain for umockdev. Errors in this domain will be from the
 * #UMockdevError enumeration. See #GError for more information on error
 * domains.
 */
#define UMOCKDEV_ERROR (umockdev_error_quark ())
GQuark umockdev_error_quark (void);

/**
 * UMockdevError:
 * @UMOCKDEV_ERROR_PARSE: Syntax error in device description string or file 
 * @UMOCKDEV_ERROR_VALUE: Missing or wrong data in device description string or file 
 *
 * Error codes for #UMOCKDEV_ERROR.
 */
typedef enum
{
   UMOCKDEV_ERROR_PARSE,
   UMOCKDEV_ERROR_VALUE,
   /*< private >*/
   UMOCKDEV_NUM_ERRORS
} UMockdevError;

GType umockdev_error_get_type (void);
#define UMOCKDEV_TYPE_ERROR (umockdev_error_get_type ())

G_END_DECLS

#endif /* __UMOCKDEV_H__ */