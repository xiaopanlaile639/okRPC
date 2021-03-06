// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc.proto

#include "rpc.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace okrpc {
class RpcMessageDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RpcMessage> _instance;
} _RpcMessage_default_instance_;
}  // namespace okrpc
static void InitDefaultsscc_info_RpcMessage_rpc_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::okrpc::_RpcMessage_default_instance_;
    new (ptr) ::okrpc::RpcMessage();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::okrpc::RpcMessage::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RpcMessage_rpc_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RpcMessage_rpc_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_rpc_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_rpc_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_rpc_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_rpc_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, type_),
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, id_),
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, service_),
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, method_),
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, request_),
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, response_),
  PROTOBUF_FIELD_OFFSET(::okrpc::RpcMessage, error_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::okrpc::RpcMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::okrpc::_RpcMessage_default_instance_),
};

const char descriptor_table_protodef_rpc_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\trpc.proto\022\005okrpc\"\237\001\n\nRpcMessage\022 \n\004typ"
  "e\030\001 \001(\0162\022.okrpc.MessageType\022\n\n\002id\030\002 \001(\006\022"
  "\017\n\007service\030\003 \001(\t\022\016\n\006method\030\004 \001(\t\022\017\n\007requ"
  "est\030\005 \001(\014\022\020\n\010response\030\006 \001(\014\022\037\n\005error\030\007 \001"
  "(\0162\020.okrpc.ErrorCode*3\n\013MessageType\022\013\n\007R"
  "EQUEST\020\000\022\014\n\010RESPONSE\020\001\022\t\n\005ERROR\020\002*\201\001\n\tEr"
  "rorCode\022\014\n\010NO_ERROR\020\000\022\017\n\013WRONG_PROTO\020\001\022\016"
  "\n\nNO_SERVICE\020\002\022\r\n\tNO_METHOD\020\003\022\023\n\017INVALID"
  "_REQUEST\020\004\022\024\n\020INVALID_RESPONSE\020\005\022\013\n\007TIME"
  "OUT\020\006b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_rpc_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_rpc_2eproto_sccs[1] = {
  &scc_info_RpcMessage_rpc_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_rpc_2eproto_once;
static bool descriptor_table_rpc_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_rpc_2eproto = {
  &descriptor_table_rpc_2eproto_initialized, descriptor_table_protodef_rpc_2eproto, "rpc.proto", 373,
  &descriptor_table_rpc_2eproto_once, descriptor_table_rpc_2eproto_sccs, descriptor_table_rpc_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_rpc_2eproto::offsets,
  file_level_metadata_rpc_2eproto, 1, file_level_enum_descriptors_rpc_2eproto, file_level_service_descriptors_rpc_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_rpc_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_rpc_2eproto), true);
namespace okrpc {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_rpc_2eproto);
  return file_level_enum_descriptors_rpc_2eproto[0];
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

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ErrorCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_rpc_2eproto);
  return file_level_enum_descriptors_rpc_2eproto[1];
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
class RpcMessage::_Internal {
 public:
};

RpcMessage::RpcMessage()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:okrpc.RpcMessage)
}
RpcMessage::RpcMessage(const RpcMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  service_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_service().empty()) {
    service_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.service_);
  }
  method_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_method().empty()) {
    method_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.method_);
  }
  request_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_request().empty()) {
    request_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.request_);
  }
  response_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_response().empty()) {
    response_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.response_);
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&error_) -
    reinterpret_cast<char*>(&id_)) + sizeof(error_));
  // @@protoc_insertion_point(copy_constructor:okrpc.RpcMessage)
}

void RpcMessage::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_RpcMessage_rpc_2eproto.base);
  service_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  method_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  request_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  response_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&error_) -
      reinterpret_cast<char*>(&id_)) + sizeof(error_));
}

RpcMessage::~RpcMessage() {
  // @@protoc_insertion_point(destructor:okrpc.RpcMessage)
  SharedDtor();
}

void RpcMessage::SharedDtor() {
  service_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  method_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  request_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  response_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RpcMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RpcMessage& RpcMessage::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RpcMessage_rpc_2eproto.base);
  return *internal_default_instance();
}


void RpcMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:okrpc.RpcMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  service_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  method_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  request_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  response_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&error_) -
      reinterpret_cast<char*>(&id_)) + sizeof(error_));
  _internal_metadata_.Clear();
}

const char* RpcMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .okrpc.MessageType type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_type(static_cast<::okrpc::MessageType>(val));
        } else goto handle_unusual;
        continue;
      // fixed64 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint64>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint64);
        } else goto handle_unusual;
        continue;
      // string service = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_service(), ptr, ctx, "okrpc.RpcMessage.service");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string method = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_method(), ptr, ctx, "okrpc.RpcMessage.method");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes request = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(_internal_mutable_request(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes response = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(_internal_mutable_response(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .okrpc.ErrorCode error = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          _internal_set_error(static_cast<::okrpc::ErrorCode>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RpcMessage::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:okrpc.RpcMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .okrpc.MessageType type = 1;
  if (this->type() != 0) {
    stream->EnsureSpace(&target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_type(), target);
  }

  // fixed64 id = 2;
  if (this->id() != 0) {
    stream->EnsureSpace(&target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed64ToArray(2, this->_internal_id(), target);
  }

  // string service = 3;
  if (this->service().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_service().data(), static_cast<int>(this->_internal_service().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "okrpc.RpcMessage.service");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_service(), target);
  }

  // string method = 4;
  if (this->method().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_method().data(), static_cast<int>(this->_internal_method().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "okrpc.RpcMessage.method");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_method(), target);
  }

  // bytes request = 5;
  if (this->request().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_request(), target);
  }

  // bytes response = 6;
  if (this->response().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        6, this->_internal_response(), target);
  }

  // .okrpc.ErrorCode error = 7;
  if (this->error() != 0) {
    stream->EnsureSpace(&target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      7, this->_internal_error(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:okrpc.RpcMessage)
  return target;
}

size_t RpcMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:okrpc.RpcMessage)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string service = 3;
  if (this->service().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_service());
  }

  // string method = 4;
  if (this->method().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_method());
  }

  // bytes request = 5;
  if (this->request().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_request());
  }

  // bytes response = 6;
  if (this->response().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_response());
  }

  // fixed64 id = 2;
  if (this->id() != 0) {
    total_size += 1 + 8;
  }

  // .okrpc.MessageType type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());
  }

  // .okrpc.ErrorCode error = 7;
  if (this->error() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_error());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RpcMessage::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:okrpc.RpcMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const RpcMessage* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RpcMessage>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:okrpc.RpcMessage)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:okrpc.RpcMessage)
    MergeFrom(*source);
  }
}

void RpcMessage::MergeFrom(const RpcMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:okrpc.RpcMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.service().size() > 0) {

    service_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.service_);
  }
  if (from.method().size() > 0) {

    method_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.method_);
  }
  if (from.request().size() > 0) {

    request_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.request_);
  }
  if (from.response().size() > 0) {

    response_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.response_);
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.type() != 0) {
    _internal_set_type(from._internal_type());
  }
  if (from.error() != 0) {
    _internal_set_error(from._internal_error());
  }
}

void RpcMessage::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
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

void RpcMessage::InternalSwap(RpcMessage* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  service_.Swap(&other->service_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  method_.Swap(&other->method_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  request_.Swap(&other->request_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  response_.Swap(&other->response_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(id_, other->id_);
  swap(type_, other->type_);
  swap(error_, other->error_);
}

::PROTOBUF_NAMESPACE_ID::Metadata RpcMessage::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace okrpc
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::okrpc::RpcMessage* Arena::CreateMaybeMessage< ::okrpc::RpcMessage >(Arena* arena) {
  return Arena::CreateInternal< ::okrpc::RpcMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
