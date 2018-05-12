#include "sender_report.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using mixerengine::rtcp::SenderReport;

namespace mixerengine {

namespace {
const uint32_t kSenderSsrc = 0x12345678;
const NtpTime kNtp(0x11121418, 0x22242628);
const uint32_t kRtpTimestamp = 0x33343536;
const uint32_t kPacketCount = 0x44454647;
const uint32_t kOctetCount = 0x55565758;
}

TEST(RtcpPacketSenderReportTest, CreateWithoutReportBlocks) {
  SenderReport sr;
  sr.SetSenderSsrc(kSenderSsrc);
  sr.SetNtp(kNtp);
  sr.SetRtpTimestamp(kRtpTimestamp);
  sr.SetPacketCount(kPacketCount);
  sr.SetOctetCount(kOctetCount);

  EXPECT_EQ(kSenderSsrc, sr.sender_ssrc());
  EXPECT_EQ(kNtp, sr.ntp());
  EXPECT_EQ(kRtpTimestamp, sr.rtp_timestamp());
  EXPECT_EQ(kPacketCount, sr.sender_packet_count());
  EXPECT_EQ(kOctetCount, sr.sender_octet_count());
}

TEST(RtcpPacketSenderReportTest, TestEqualOperator) {
}
}  // namespace mixerengine
