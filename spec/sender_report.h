#ifndef MIXERENGINE_INCLUDE_SPEC_SENDER_REPORT_H_
#define MIXERENGINE_INCLUDE_SPEC_SENDER_REPORT_H_

#include <stdint.h>

#include "ntp_time.h"

namespace mixerengine {
namespace rtcp {

class SenderReport {
 public:

  SenderReport();
  ~SenderReport();

  void SetSenderSsrc(uint32_t ssrc) { sender_ssrc_ = ssrc; }
  void SetNtp(NtpTime ntp) { ntp_ = ntp; }

  void SetRtpTimestamp(uint32_t rtp_timestamp) { 
    rtp_timestamp_ = rtp_timestamp;
  }

  void SetPacketCount(uint32_t packet_count) {
    sender_packet_count_ = packet_count;
  }

  void SetOctetCount(uint32_t octet_count) {
    sender_octet_count_ = octet_count;
  }

  uint32_t sender_ssrc() const { return sender_ssrc_; }
  NtpTime ntp() const { return ntp_; }
  uint32_t rtp_timestamp() const { return rtp_timestamp_; }
  uint32_t sender_packet_count() const { return sender_packet_count_; }
  uint32_t sender_octet_count() const { return sender_octet_count_; }

 private:
  uint32_t sender_ssrc_;
  NtpTime ntp_;
  uint32_t rtp_timestamp_;
  uint32_t sender_packet_count_;
  uint32_t sender_octet_count_;
};

}  // rtcp
}  // mixerengine

#endif  // MIXERENGINE_INCLUDE_SPEC_SENDER_REPORT_H_
