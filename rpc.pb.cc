// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc.proto

#include "rpc.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
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
//
namespace okrpc {
class RpcMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<RpcMessage>
      _instance;
} _RpcMessage_default_instance_;
}  // namespace okrpc
namespace protobuf_rpc_2eproto {
static void InitDefaultsRpcMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::okrpc::_RpcMessage_default_instance_;
    new (ptr) ::okrpc::RpcMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::okrpc::RpcMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_RpcMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsRpcMessage}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_RpcMessage.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, service_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, method_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, request_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, response_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::okrpc::RpcMessage, error_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::okrpc::RpcMessage)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::okrpc::_RpcMessage_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "rpc.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\trpc.proto\022\005okrpc\"\237\001\n\nRpcMessage\022 \n\004typ"
      "e\030\001 \001(\0162\022.okrpc.MessageType\022\n\n\002id\030\002 \001(\006\022"
      "\017\n\007service\030\003 \001(\t\022\016\n\006method\030\004 \001(\t\022\017\n\007requ"
      "est\030\005 \001(\014\022\020\n\010response\030\006 \001(\014\022\037\n\005error\030\007 \001"
      "(\0162\020.okrpc.ErrorCode*3\n\013MessageType\022\013\n\007R"
      "EQUEST\020\000\022\014\n\010RESPONSE\020\001\022\t\n\005ERROR\020\002*\201\001\n\tEr"
      "rorCode\022\014\n\010NO_ERROR\020\000\022\017\n\013WRONG_PROTO\020\001\022\016"
      "\n\nNO_SERVICE\020\002\022\r\n\tNO_METHOD\020\003\022\023\n\017INVALID"
      "_REQUEST\020\004\022\024\n\020INVALID_RESPONSE\020\005\022\013\n\007TIME"
      "OUT\020\006B\'\n\033com.chenshuo.muduo.protorpcB\010Rp"
      "cProtob\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 414);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rpc.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_rpc_2eproto
namespace okrpc {
const ::google::protobuf::EnumDescriptor* MessageType_descriptor() {
  protobuf_rpc_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_rpc_2eproto::file_level_enum_descriptors[0];
}
bool MessageType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* ErrorCode_descriptor() {
  protobuf_rpc_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_rpc_2eproto::file_level_enum_descriptors[1];
}
bool ErrorCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void RpcMessage::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RpcMessage::kTypeFieldNumber;
const int RpcMessage::kIdFieldNumber;
const int RpcMessage::kServiceFieldNumber;
const int RpcMessage::kMethodFieldNumber;
const int RpcMessage::kRequestFieldNumber;
const int RpcMessage::kResponseFieldNumber;
const int RpcMessage::kErrorFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RpcMessage::RpcMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_rpc_2eproto::scc_info_RpcMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:okrpc.RpcMessage)
}
RpcMessage::RpcMessage(const RpcMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  service_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.service().size() > 0) {
    service_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.service_);
  }
  method_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.method().size() > 0) {
    method_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.method_);
  }
  request_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.request().size() > 0) {
    request_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.request_);
  }
  response_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.response().size() > 0) {
    response_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.response_);
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&error_) -
    reinterpret_cast<char*>(&id_)) + sizeof(error_));
  // @@protoc_insertion_point(copy_constructor:okrpc.RpcMessage)
}

void RpcMessage::SharedCtor() {
  service_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  method_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  request_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  response_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&error_) -
      reinterpret_cast<char*>(&id_)) + sizeof(error_));
}

RpcMessage::~RpcMessage() {
  // @@protoc_insertion_point(destructor:okrpc.RpcMessage)
  SharedDtor();
}

void RpcMessage::SharedDtor() {
  service_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  method_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  request_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  response_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void RpcMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* RpcMessage::descriptor() {
  ::protobuf_rpc_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_rpc_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RpcMessage& RpcMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_rpc_2eproto::scc_info_RpcMessage.base);
  return *internal_default_instance();
}


void RpcMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:okrpc.RpcMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  service_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  method_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  request_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  response_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&error_) -
      reinterpret_cast<char*>(&id_)) + sizeof(error_));
  _internal_metadata_.Clear();
}

bool RpcMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:okrpc.RpcMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .okrpc.MessageType type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::okrpc::MessageType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // fixed64 id = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string service = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_service()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->service().data(), static_cast<int>(this->service().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "okrpc.RpcMessage.service"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string method = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_method()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->method().data(), static_cast<int>(this->method().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "okrpc.RpcMessage.method"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes request = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_request()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes response = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_response()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .okrpc.ErrorCode error = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_error(static_cast< ::okrpc::ErrorCode >(value));
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
  // @@protoc_insertion_point(parse_success:okrpc.RpcMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:okrpc.RpcMessage)
  return false;
#undef DO_
}

void RpcMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:okrpc.RpcMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .okrpc.MessageType type = 1;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // fixed64 id = 2;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(2, this->id(), output);
  }

  // string service = 3;
  if (this->service().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->service().data(), static_cast<int>(this->service().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "okrpc.RpcMessage.service");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->service(), output);
  }

  // string method = 4;
  if (this->method().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->method().data(), static_cast<int>(this->method().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "okrpc.RpcMessage.method");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->method(), output);
  }

  // bytes request = 5;
  if (this->request().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      5, this->request(), output);
  }

  // bytes response = 6;
  if (this->response().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      6, this->response(), output);
  }

  // .okrpc.ErrorCode error = 7;
  if (this->error() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      7, this->error(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:okrpc.RpcMessage)
}

::google::protobuf::uint8* RpcMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:okrpc.RpcMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .okrpc.MessageType type = 1;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // fixed64 id = 2;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(2, this->id(), target);
  }

  // string service = 3;
  if (this->service().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->service().data(), static_cast<int>(this->service().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "okrpc.RpcMessage.service");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->service(), target);
  }

  // string method = 4;
  if (this->method().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->method().data(), static_cast<int>(this->method().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "okrpc.RpcMessage.method");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->method(), target);
  }

  // bytes request = 5;
  if (this->request().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->request(), target);
  }

  // bytes response = 6;
  if (this->response().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->response(), target);
  }

  // .okrpc.ErrorCode error = 7;
  if (this->error() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      7, this->error(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:okrpc.RpcMessage)
  return target;
}

size_t RpcMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:okrpc.RpcMessage)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string service = 3;
  if (this->service().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->service());
  }

  // string method = 4;
  if (this->method().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->method());
  }

  // bytes request = 5;
  if (this->request().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->request());
  }

  // bytes response = 6;
  if (this->response().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->response());
  }

  // fixed64 id = 2;
  if (this->id() != 0) {
    total_size += 1 + 8;
  }

  // .okrpc.MessageType type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  // .okrpc.ErrorCode error = 7;
  if (this->error() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->error());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RpcMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:okrpc.RpcMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const RpcMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RpcMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:okrpc.RpcMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:okrpc.RpcMessage)
    MergeFrom(*source);
  }
}

void RpcMessage::MergeFrom(const RpcMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:okrpc.RpcMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.service().size() > 0) {

    service_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.service_);
  }
  if (from.method().size() > 0) {

    method_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.method_);
  }
  if (from.request().size() > 0) {

    request_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.request_);
  }
  if (from.response().size() > 0) {

    response_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.response_);
  }
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
  if (from.error() != 0) {
    set_error(from.error());
  }
}

void RpcMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:okrpc.RpcMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RpcMessage::CopyFrom(const RpcMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:okrpc.RpcMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcMessage::IsInitialized() const {
  return true;
}

void RpcMessage::Swap(RpcMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RpcMessage::InternalSwap(RpcMessage* other) {
  using std::swap;
  service_.Swap(&other->service_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  method_.Swap(&other->method_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  request_.Swap(&other->request_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  response_.Swap(&other->response_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(id_, other->id_);
  swap(type_, other->type_);
  swap(error_, other->error_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata RpcMessage::GetMetadata() const {
  protobuf_rpc_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_rpc_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace okrpc
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::okrpc::RpcMessage* Arena::CreateMaybeMessage< ::okrpc::RpcMessage >(Arena* arena) {
  return Arena::CreateInternal< ::okrpc::RpcMessage >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
