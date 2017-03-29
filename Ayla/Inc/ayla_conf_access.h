/*
 * Copyright 2014 Ayla Networks, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of Ayla Networks, Inc.
 */
#ifndef __AYLA_CONF_ACCESS_H__
#define __AYLA_CONF_ACCESS_H__

#ifdef __cplusplus
	extern "C" {
#endif

#include "ayla_protocol.h"

#define CONF_TOKEN(val, name)	CT_##name = val,

enum conf_token {
	CT_INVALID_TOKEN = 0,	/* not to be converted to a name */

	/*
	 * These name/pairs must not change after the first release for
	 * upward compatibility with older configurations or customer code.
	 */
	/* 0 is absolutely reserved as an error return, do not use otherwise */
	CONF_TOKEN(1, enable)
	CONF_TOKEN(2, ready)
	CONF_TOKEN(3, sys)
	CONF_TOKEN(4, wifi)
	CONF_TOKEN(5, server)
	CONF_TOKEN(6, client)
	CONF_TOKEN(7, ssl)
	CONF_TOKEN(8, status)
	CONF_TOKEN(9, start)
	CONF_TOKEN(0x0a, complete)
	CONF_TOKEN(0x0b, ip)
	CONF_TOKEN(0x0c, n)		/* indicates an index follows */
	CONF_TOKEN(0x0d, time)
	CONF_TOKEN(0x0e, power)
	CONF_TOKEN(0x0f, user)
	CONF_TOKEN(0x10, version)
	/* reserved gap for frequently-used tokens */
	CONF_TOKEN(0x14, model)
	CONF_TOKEN(0x15, serial)
	CONF_TOKEN(0x16, mfg_serial)
	CONF_TOKEN(0x17, hostname)
	CONF_TOKEN(0x18, timezone)
	CONF_TOKEN(0x19, timezone_valid)
	CONF_TOKEN(0x1a, mfg_mode)
	CONF_TOKEN(0x1b, dev_id)
	CONF_TOKEN(0x1c, setup_mode)
	CONF_TOKEN(0x1d, mfg_model)
	CONF_TOKEN(0x1e, sim)
	/* reserved gap */
	CONF_TOKEN(0x25, profile)
	CONF_TOKEN(0x26, ssid)
	CONF_TOKEN(0x27, security)
	CONF_TOKEN(0x28, none)
	CONF_TOKEN(0x29, WEP)
	CONF_TOKEN(0x2a, WPA)
	CONF_TOKEN(0x2b, WPA2_Personal)
	CONF_TOKEN(0x2c, key)
	CONF_TOKEN(0x2d, pri)
	CONF_TOKEN(0x2e, scan)
	CONF_TOKEN(0x2f, time_limit)
	CONF_TOKEN(0x30, save_on_ap_connect)
	CONF_TOKEN(0x31, save_on_server_connect)
	CONF_TOKEN(0x32, max_perf)
	CONF_TOKEN(0x33, en_bind)
	CONF_TOKEN(0x34, ap_mode)
	CONF_TOKEN(0x35, rssi)
	CONF_TOKEN(0x36, bssid)
	CONF_TOKEN(0x37, bars)
	CONF_TOKEN(0x38, poll_interval)
	CONF_TOKEN(0x39, addr)
	CONF_TOKEN(0x3a, mac_addr)
	CONF_TOKEN(0x3b, ant)
	/* reserved gap */
	CONF_TOKEN(0x43, connected)
	CONF_TOKEN(0x44, cert)
	CONF_TOKEN(0x45, private_key)
	CONF_TOKEN(0x46, ca)
	CONF_TOKEN(0x47, gif)
	CONF_TOKEN(0x48, oem)
	CONF_TOKEN(0x49, log)
	CONF_TOKEN(0x4a, mod)
	CONF_TOKEN(0x4b, mask)
	CONF_TOKEN(0x4c, chan)
	CONF_TOKEN(0x4d, error)
	CONF_TOKEN(0x4e, link)
	CONF_TOKEN(0x4f, reg)
	CONF_TOKEN(0x50, default)
	CONF_TOKEN(0x51, min)
	CONF_TOKEN(0x52, standby)
	CONF_TOKEN(0x53, mode)
	CONF_TOKEN(0x54, dhcp)
	CONF_TOKEN(0x55, gw)
	CONF_TOKEN(0x56, snapshot)
	CONF_TOKEN(0x57, hist)
	CONF_TOKEN(0x58, source)
	CONF_TOKEN(0x59, WPS)
	CONF_TOKEN(0x5a, listen)
	CONF_TOKEN(0x5b, interval)
	CONF_TOKEN(0x5c, auto)
	CONF_TOKEN(0x5d, current)
	CONF_TOKEN(0x5e, awake_time)
	CONF_TOKEN(0x5f, standby_powered)
	CONF_TOKEN(0x60, unconf_powered)
	CONF_TOKEN(0x61, metric)
	CONF_TOKEN(0x62, http)
	CONF_TOKEN(0x63, tcp)
	CONF_TOKEN(0x64, count)
	CONF_TOKEN(0x65, locale)
	CONF_TOKEN(0x66, lan)
	CONF_TOKEN(0x67, setup_ios_app)
	CONF_TOKEN(0x68, notify)
	CONF_TOKEN(0x69, gpio)
	/* reserved gap */
	CONF_TOKEN(0x70, value)
	CONF_TOKEN(0x71, prop)
	CONF_TOKEN(0x72, port)
	CONF_TOKEN(0x73, sched)
	CONF_TOKEN(0x74, dst_active)
	CONF_TOKEN(0x75, dst_change)
	CONF_TOKEN(0x76, dst_valid)
	CONF_TOKEN(0x77, dns)
	CONF_TOKEN(0x78, hw)
	CONF_TOKEN(0x79, rtc_src)

	CT_END_TOKEN
} PACKED;

#undef CONF_TOKEN



/*
 * In conf_access.c.
 */
extern void (*conf_ota_cb)(int type, void *buf, size_t len);
extern char conf_dsn[];
extern char conf_model[];

#ifdef AYLA_REG_TOKEN
extern char conf_reg_token[];
#endif

/*
 * Receive a configuration item.
 */
void conf_rx(void *buf, size_t len);

/*
 * enum conf_token conf_tokens[] = {CT_token0, CT_token1};
 * int ntokens = sizeof (conf_tokens) / sizeof (conf_tokens[0];
 * int val_type;
 * int val;
 * int val_sz = sizeof (val);
 *
 * conf_write(conf_tokens, ntokens, val_type, val, val_sz, ...);
 *
 * Arguments to conf_write are repeated in a set of 5,
 * 1. config tokens,
 * 2. number of config tokens,
 * 3. config variable type id
 * 4. pointer to value conf variable should be set to
 * 5. size of the conf variable value
 */
int conf_write(int cnt, ...);

/*
 * Send GET_CONF request.
 */
int conf_read(const enum conf_token * const tokens, unsigned int ntokens,
    void (*cb)(void *buf, size_t len));

void conf_set_cb(void (*cb)(void *buf, size_t len));
void conf_poll(void);

#ifdef AYLA_WIFI_JOIN

extern char conf_wifi_ssid[];
extern s8 conf_wifi_bars;
extern u8 conf_wifi_ap_mode;
///////////////////////////////////////////////////////////////////////////////
// zhaojianchuan 2016.04.28
extern char conf_mfg_model[];
extern char conf_mfg_serial[];
extern char conf_oem[];
extern char conf_oem_model[];
extern char conf_ssid[];
extern int conf_time;
extern char update_utc_time_enable;
extern struct timezone_settings conf_timezone_settings;
extern struct daylight_settings conf_daylight_info;
///////////////////////////////////////////////////////////////////////////////

/*
 * Ask module for wifi information every 'poll_secs'
 */
u8 conf_wifi_poll(u8 poll_secs);

/*
 * Sends a wifi join command over Serial. This'll get module to attempt to
 * join the specified network.
 */
int conf_wifi_join(char *ssid, int ssid_len, char *key, int klen, u8 sec_type);

/*
 * Sends a wifi delete command over Serial. This'll get module to leave and
 * forget the specified network.
 */
int conf_wifi_leave(char *ssid, int slen);

/*
 * This routine gets module to start it's wifi accesspoint. AP mode
 * will stay in effect until next restart, or until there is a wifi
 * configuration change (e.g. new network configuration gets added).
 */
int conf_wifi_start_ap(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __AYLA_CONF_ACCESS_H__ */
