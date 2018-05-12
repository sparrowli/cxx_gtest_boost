#ifndef MIXERENGINE_INCLUDE_SPEC_NTP_TIME_H_
#define MIXERENGINE_INCLUDE_SPEC_NTP_TIME_H_

#include <stdint.h>

class NtpTime
{
 public:
  static const uint64_t kFractionsPerSecond = 0x100000000;
  NtpTime() : value_(0) {}
  explicit NtpTime(uint64_t value) : value_(value) {}
  NtpTime(uint32_t seconds, uint32_t fractions)
      : value_(seconds * kFractionsPerSecond + fractions) {}
  /*
  NtpTime(const NtpTime& other) = default;

  NtpTime& operator=(const NtpTime&) = default;
  */
  operator uint64_t() const { return value_; }


  void Set(uint32_t seconds, uint32_t fractions) 
  {
    value_ = seconds * kFractionsPerSecond + fractions;
  }
  void Reset() { value_ = 0; }

  int64_t ToMs() const
  {
    static const double kNtpFracPerMs = 4.294967296E6; // 2^32 / 1000
    const double frac_ms = static_cast<double>(fractions()) / kNtpFracPerMs;
    return 1000 * static_cast<int64_t>(seconds()) +
           static_cast<int64_t>(frac_ms + 0.5);
  }

  bool Valid() const { return value_ != 0; }

  uint32_t seconds() const { return value_ / kFractionsPerSecond; }
  uint32_t fractions() const { return value_ % kFractionsPerSecond; }

 private:
  uint64_t value_;
};

inline bool operator==(const NtpTime& n1, const NtpTime& n2)
{
  return static_cast<uint64_t>(n1) == static_cast<uint64_t>(n2);
}

inline bool operator!=(const NtpTime& n1, const NtpTime& n2)
{
  return !(n1 == n2);
}
#endif  // MIXERENGINE_INCLUDE_SPEC_NTP_TIME_H_
