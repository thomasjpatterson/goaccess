/**
 *    ______      ___
 *   / ____/___  /   | _____________  __________
 *  / / __/ __ \/ /| |/ ___/ ___/ _ \/ ___/ ___/
 * / /_/ / /_/ / ___ / /__/ /__/  __(__  |__  )
 * \____/\____/_/  |_\___/\___/\___/____/____/
 *
 * The MIT License (MIT)
 * Copyright (c) 2009-2016 Gerardo Orellana <hello @ goaccess.io>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef GSTORAGE_H_INCLUDED
#define GSTORAGE_H_INCLUDED

#include "commons.h"
#include "parser.h"

/* Total number of storage metrics (GSMetric) */
#define GSMTRC_TOTAL 14

/* Enumerated Storage Metrics */
typedef enum GSMetric_
{
  MTRC_KEYMAP,
  MTRC_ROOTMAP,
  MTRC_DATAMAP,
  MTRC_UNIQMAP,
  MTRC_ROOT,
  MTRC_HITS,
  MTRC_VISITORS,
  MTRC_BW,
  MTRC_CUMTS,
  MTRC_MAXTS,
  MTRC_METHODS,
  MTRC_PROTOCOLS,
  MTRC_AGENTS,
  MTRC_METADATA,
} GSMetric;

GMetrics *new_gmetrics (void);

char *store_get_datamap (GModule module, int key);
char *store_get_hostname (const char *host);
char *store_get_method (GModule module, int key);
char *store_get_protocol (GModule module, int key);
char *store_get_root (GModule module, int key);
GRawData *store_parse_raw_data(GModule module);
int *int2ptr (int val);
int store_get_hits (GModule module, int key);
int store_get_visitors (GModule module, int key);
uint32_t store_get_size_datamap(GModule module);
uint32_t store_get_size_uniqmap(GModule module);
uint64_t store_get_bw (GModule module, int key);
uint64_t store_get_cumts (GModule module, int key);
uint64_t store_get_maxts (GModule module, int key);
uint64_t *uint642ptr (uint64_t val);
void *get_storage_metric_by_module (GModule module, GSMetric metric);
void *get_storage_metric (GModule module, GSMetric metric);
void set_data_metrics (GMetrics * ometrics, GMetrics ** nmetrics, GPercTotals totals);
void set_module_totals (GModule module, GPercTotals * totals);

#endif // for #ifndef GSTORAGE_H
