// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sprout_math.proto

#include "sprout_math.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace Sprout {
class ProcessForecastIntervalDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ProcessForecastInterval>
      _instance;
} _ProcessForecastInterval_default_instance_;
class CountProbabilityDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CountProbability>
      _instance;
} _CountProbability_default_instance_;
class SproutModelDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SproutModel>
      _instance;
} _SproutModel_default_instance_;
}  // namespace Sprout
namespace protobuf_sprout_5fmath_2eproto {
void InitDefaultsProcessForecastIntervalImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_sprout_5fmath_2eproto::InitDefaultsCountProbability();
  {
    void* ptr = &::Sprout::_ProcessForecastInterval_default_instance_;
    new (ptr) ::Sprout::ProcessForecastInterval();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Sprout::ProcessForecastInterval::InitAsDefaultInstance();
}

void InitDefaultsProcessForecastInterval() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsProcessForecastIntervalImpl);
}

void InitDefaultsCountProbabilityImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::Sprout::_CountProbability_default_instance_;
    new (ptr) ::Sprout::CountProbability();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Sprout::CountProbability::InitAsDefaultInstance();
}

void InitDefaultsCountProbability() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsCountProbabilityImpl);
}

void InitDefaultsSproutModelImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_sprout_5fmath_2eproto::InitDefaultsProcessForecastInterval();
  {
    void* ptr = &::Sprout::_SproutModel_default_instance_;
    new (ptr) ::Sprout::SproutModel();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Sprout::SproutModel::InitAsDefaultInstance();
}

void InitDefaultsSproutModel() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSproutModelImpl);
}

::google::protobuf::Metadata file_level_metadata[3];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Sprout::ProcessForecastInterval, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Sprout::ProcessForecastInterval, count_probabilities_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Sprout::CountProbability, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Sprout::CountProbability, count_probability_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Sprout::SproutModel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Sprout::SproutModel, intervals_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Sprout::ProcessForecastInterval)},
  { 6, -1, sizeof(::Sprout::CountProbability)},
  { 12, -1, sizeof(::Sprout::SproutModel)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::Sprout::_ProcessForecastInterval_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::Sprout::_CountProbability_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::Sprout::_SproutModel_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "sprout_math.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\021sprout_math.proto\022\006Sprout\"P\n\027ProcessFo"
      "recastInterval\0225\n\023count_probabilities\030\001 "
      "\003(\0132\030.Sprout.CountProbability\"-\n\020CountPr"
      "obability\022\031\n\021count_probability\030\002 \003(\001\"A\n\013"
      "SproutModel\0222\n\tintervals\030\003 \003(\0132\037.Sprout."
      "ProcessForecastIntervalb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 231);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "sprout_math.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_sprout_5fmath_2eproto
namespace Sprout {

// ===================================================================

void ProcessForecastInterval::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ProcessForecastInterval::kCountProbabilitiesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ProcessForecastInterval::ProcessForecastInterval()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_sprout_5fmath_2eproto::InitDefaultsProcessForecastInterval();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Sprout.ProcessForecastInterval)
}
ProcessForecastInterval::ProcessForecastInterval(const ProcessForecastInterval& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      count_probabilities_(from.count_probabilities_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Sprout.ProcessForecastInterval)
}

void ProcessForecastInterval::SharedCtor() {
  _cached_size_ = 0;
}

ProcessForecastInterval::~ProcessForecastInterval() {
  // @@protoc_insertion_point(destructor:Sprout.ProcessForecastInterval)
  SharedDtor();
}

void ProcessForecastInterval::SharedDtor() {
}

void ProcessForecastInterval::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ProcessForecastInterval::descriptor() {
  ::protobuf_sprout_5fmath_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sprout_5fmath_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ProcessForecastInterval& ProcessForecastInterval::default_instance() {
  ::protobuf_sprout_5fmath_2eproto::InitDefaultsProcessForecastInterval();
  return *internal_default_instance();
}

ProcessForecastInterval* ProcessForecastInterval::New(::google::protobuf::Arena* arena) const {
  ProcessForecastInterval* n = new ProcessForecastInterval;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ProcessForecastInterval::Clear() {
// @@protoc_insertion_point(message_clear_start:Sprout.ProcessForecastInterval)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  count_probabilities_.Clear();
  _internal_metadata_.Clear();
}

bool ProcessForecastInterval::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Sprout.ProcessForecastInterval)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Sprout.CountProbability count_probabilities = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_count_probabilities()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Sprout.ProcessForecastInterval)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Sprout.ProcessForecastInterval)
  return false;
#undef DO_
}

void ProcessForecastInterval::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Sprout.ProcessForecastInterval)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Sprout.CountProbability count_probabilities = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->count_probabilities_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->count_probabilities(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Sprout.ProcessForecastInterval)
}

::google::protobuf::uint8* ProcessForecastInterval::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Sprout.ProcessForecastInterval)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Sprout.CountProbability count_probabilities = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->count_probabilities_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->count_probabilities(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Sprout.ProcessForecastInterval)
  return target;
}

size_t ProcessForecastInterval::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Sprout.ProcessForecastInterval)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .Sprout.CountProbability count_probabilities = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->count_probabilities_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->count_probabilities(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ProcessForecastInterval::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Sprout.ProcessForecastInterval)
  GOOGLE_DCHECK_NE(&from, this);
  const ProcessForecastInterval* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ProcessForecastInterval>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Sprout.ProcessForecastInterval)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Sprout.ProcessForecastInterval)
    MergeFrom(*source);
  }
}

void ProcessForecastInterval::MergeFrom(const ProcessForecastInterval& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Sprout.ProcessForecastInterval)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  count_probabilities_.MergeFrom(from.count_probabilities_);
}

void ProcessForecastInterval::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Sprout.ProcessForecastInterval)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ProcessForecastInterval::CopyFrom(const ProcessForecastInterval& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Sprout.ProcessForecastInterval)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProcessForecastInterval::IsInitialized() const {
  return true;
}

void ProcessForecastInterval::Swap(ProcessForecastInterval* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ProcessForecastInterval::InternalSwap(ProcessForecastInterval* other) {
  using std::swap;
  count_probabilities_.InternalSwap(&other->count_probabilities_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ProcessForecastInterval::GetMetadata() const {
  protobuf_sprout_5fmath_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sprout_5fmath_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void CountProbability::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CountProbability::kCountProbabilityFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CountProbability::CountProbability()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_sprout_5fmath_2eproto::InitDefaultsCountProbability();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Sprout.CountProbability)
}
CountProbability::CountProbability(const CountProbability& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      count_probability_(from.count_probability_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Sprout.CountProbability)
}

void CountProbability::SharedCtor() {
  _cached_size_ = 0;
}

CountProbability::~CountProbability() {
  // @@protoc_insertion_point(destructor:Sprout.CountProbability)
  SharedDtor();
}

void CountProbability::SharedDtor() {
}

void CountProbability::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CountProbability::descriptor() {
  ::protobuf_sprout_5fmath_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sprout_5fmath_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CountProbability& CountProbability::default_instance() {
  ::protobuf_sprout_5fmath_2eproto::InitDefaultsCountProbability();
  return *internal_default_instance();
}

CountProbability* CountProbability::New(::google::protobuf::Arena* arena) const {
  CountProbability* n = new CountProbability;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CountProbability::Clear() {
// @@protoc_insertion_point(message_clear_start:Sprout.CountProbability)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  count_probability_.Clear();
  _internal_metadata_.Clear();
}

bool CountProbability::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Sprout.CountProbability)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated double count_probability = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, this->mutable_count_probability())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 1, 18u, input, this->mutable_count_probability())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Sprout.CountProbability)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Sprout.CountProbability)
  return false;
#undef DO_
}

void CountProbability::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Sprout.CountProbability)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated double count_probability = 2;
  if (this->count_probability_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _count_probability_cached_byte_size_));
    ::google::protobuf::internal::WireFormatLite::WriteDoubleArray(
      this->count_probability().data(), this->count_probability_size(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Sprout.CountProbability)
}

::google::protobuf::uint8* CountProbability::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Sprout.CountProbability)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated double count_probability = 2;
  if (this->count_probability_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _count_probability_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteDoubleNoTagToArray(this->count_probability_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Sprout.CountProbability)
  return target;
}

size_t CountProbability::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Sprout.CountProbability)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated double count_probability = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->count_probability_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _count_probability_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CountProbability::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Sprout.CountProbability)
  GOOGLE_DCHECK_NE(&from, this);
  const CountProbability* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CountProbability>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Sprout.CountProbability)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Sprout.CountProbability)
    MergeFrom(*source);
  }
}

void CountProbability::MergeFrom(const CountProbability& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Sprout.CountProbability)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  count_probability_.MergeFrom(from.count_probability_);
}

void CountProbability::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Sprout.CountProbability)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CountProbability::CopyFrom(const CountProbability& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Sprout.CountProbability)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CountProbability::IsInitialized() const {
  return true;
}

void CountProbability::Swap(CountProbability* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CountProbability::InternalSwap(CountProbability* other) {
  using std::swap;
  count_probability_.InternalSwap(&other->count_probability_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata CountProbability::GetMetadata() const {
  protobuf_sprout_5fmath_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sprout_5fmath_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void SproutModel::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SproutModel::kIntervalsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SproutModel::SproutModel()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_sprout_5fmath_2eproto::InitDefaultsSproutModel();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Sprout.SproutModel)
}
SproutModel::SproutModel(const SproutModel& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      intervals_(from.intervals_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Sprout.SproutModel)
}

void SproutModel::SharedCtor() {
  _cached_size_ = 0;
}

SproutModel::~SproutModel() {
  // @@protoc_insertion_point(destructor:Sprout.SproutModel)
  SharedDtor();
}

void SproutModel::SharedDtor() {
}

void SproutModel::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SproutModel::descriptor() {
  ::protobuf_sprout_5fmath_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sprout_5fmath_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SproutModel& SproutModel::default_instance() {
  ::protobuf_sprout_5fmath_2eproto::InitDefaultsSproutModel();
  return *internal_default_instance();
}

SproutModel* SproutModel::New(::google::protobuf::Arena* arena) const {
  SproutModel* n = new SproutModel;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SproutModel::Clear() {
// @@protoc_insertion_point(message_clear_start:Sprout.SproutModel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  intervals_.Clear();
  _internal_metadata_.Clear();
}

bool SproutModel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Sprout.SproutModel)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Sprout.ProcessForecastInterval intervals = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_intervals()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Sprout.SproutModel)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Sprout.SproutModel)
  return false;
#undef DO_
}

void SproutModel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Sprout.SproutModel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Sprout.ProcessForecastInterval intervals = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->intervals_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->intervals(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Sprout.SproutModel)
}

::google::protobuf::uint8* SproutModel::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Sprout.SproutModel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Sprout.ProcessForecastInterval intervals = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->intervals_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, this->intervals(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Sprout.SproutModel)
  return target;
}

size_t SproutModel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Sprout.SproutModel)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .Sprout.ProcessForecastInterval intervals = 3;
  {
    unsigned int count = static_cast<unsigned int>(this->intervals_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->intervals(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SproutModel::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Sprout.SproutModel)
  GOOGLE_DCHECK_NE(&from, this);
  const SproutModel* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SproutModel>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Sprout.SproutModel)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Sprout.SproutModel)
    MergeFrom(*source);
  }
}

void SproutModel::MergeFrom(const SproutModel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Sprout.SproutModel)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  intervals_.MergeFrom(from.intervals_);
}

void SproutModel::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Sprout.SproutModel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SproutModel::CopyFrom(const SproutModel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Sprout.SproutModel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SproutModel::IsInitialized() const {
  return true;
}

void SproutModel::Swap(SproutModel* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SproutModel::InternalSwap(SproutModel* other) {
  using std::swap;
  intervals_.InternalSwap(&other->intervals_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SproutModel::GetMetadata() const {
  protobuf_sprout_5fmath_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_sprout_5fmath_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Sprout

// @@protoc_insertion_point(global_scope)
