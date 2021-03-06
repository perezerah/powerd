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


#include <lunaservice.h>
/** 
 * @brief If from batterycheck, the reason why we woke up.
 */
enum {
    BATTERYCHECK_NONE = 0,
    BATTERYCHECK_THRESHOLD_CHANGED,
    BATTERYCHECK_CRITICAL_LOW_BATTERY,
    BATTERYCHECK_CRITICAL_TEMPERATURE,
    BATTERYCHECK_END,
};

enum {
    kPowerEventNone,
    kPowerEventForceSuspend,
    kPowerEventIdleEvent,
};
typedef int PowerEvent;


void ScheduleIdleCheck(int interval_ms, bool fromPoll);
void TriggerSuspend(const char *cause, PowerEvent power_event);

