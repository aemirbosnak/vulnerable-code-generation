//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

static const uint32_t DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31,
                                             30, 31, 30, 31};

static uint32_t is_leap_year(uint32_t year) {
  return !(year % 4) && (year % 100 || !(year % 400));
}

static uint64_t days_from_epoch(uint32_t year, uint32_t month, uint32_t day) {
  uint64_t days = 0;
  --year;
  while (year >= 1970) {
    days += 365 + is_leap_year(year);
    --year;
  }
  for (uint32_t i = 0; i < month - 1; ++i) {
    days += DAYS_IN_MONTH[i];
  }
  if (month > 2 && is_leap_year(year + 1)) {
    ++days;
  }
  return days + day - 1;
}

static void convert_date(uint64_t epoch_days) {
  uint32_t year = 1970;
  uint32_t month = 1;
  uint32_t day = 1;
  int64_t days_to_subtract;
  while (epoch_days >= 365 + is_leap_year(year)) {
    epoch_days -= 365 + is_leap_year(year);
    ++year;
  }
  while (epoch_days >= DAYS_IN_MONTH[month - 1] + (month == 2 &&
                                                     is_leap_year(year))) {
    epoch_days -= DAYS_IN_MONTH[month - 1] + (month == 2 && is_leap_year(year));
    ++month;
  }
  day += epoch_days;
  printf("Date: %3" PRIu32 "-%02" PRIu32 "-%02" PRIu32 "\n", year, month, day);
}

int main(void) {
  time_t epoch_time;
  struct tm *epoch_tm;
  time(&epoch_time);
  epoch_tm = localtime(&epoch_time);
  uint64_t epoch_days = days_from_epoch(epoch_tm->tm_year + 1900, epoch_tm->tm_mon + 1,
                                         epoch_tm->tm_mday);
  printf("Epoch days: %" PRIu64 "\n", epoch_days);
  convert_date(epoch_days - 1);
  convert_date(epoch_days);
  convert_date(epoch_days + 1);
  return 0;
}