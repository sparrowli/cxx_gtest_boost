#include "sender_report.h"

namespace mixerengine {
namespace rtcp {

SenderReport::SenderReport()
    : sender_ssrc_(0),
      rtp_timestamp_(0),
      sender_packet_count_(0),
      sender_octet_count_(0)
{}

SenderReport::~SenderReport() {}

}  // rtcp
}  // mixerengine
