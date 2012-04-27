/* @@@LICENSE
*
*      Copyright (c) 2007-2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */


#ifndef _INIT_H_
#define _INIT_H_

void TheOneInit(void);

enum {
    INIT_FUNC_FIRST  = 0,
    INIT_FUNC_EARLY  = 10,
    INIT_FUNC_MIDDLE = 50,
    INIT_FUNC_END    = 100,
};
typedef int InitFuncPriority;

typedef int (*InitFunc)(void);

void NamedInitFuncAdd(const char *initListName, InitFuncPriority priority, InitFunc func, const char *func_name);

#define COMMON_INIT_NAME "init-common"
/**
 * Declare a func to be inited for all devices including "simulator".
 */
#define INIT_FUNC(priority, func)                           \
static void __attribute__ ((constructor))                   \
ModuleInitializer##func(void)                               \
{                                                           \
    NamedInitFuncAdd(COMMON_INIT_NAME, priority, func, #func);    \
}

#endif