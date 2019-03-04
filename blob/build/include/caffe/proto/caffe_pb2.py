# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: caffe.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='caffe.proto',
  package='caffe',
  serialized_pb='\n\x0b\x63\x61\x66\x66\x65.proto\x12\x05\x63\x61\x66\x66\x65\"\x1c\n\tBlobShape\x12\x0f\n\x03\x64im\x18\x01 \x03(\x03\x42\x02\x10\x01\"\xcc\x01\n\tBlobProto\x12\x1f\n\x05shape\x18\x07 \x01(\x0b\x32\x10.caffe.BlobShape\x12\x10\n\x04\x64\x61ta\x18\x05 \x03(\x02\x42\x02\x10\x01\x12\x10\n\x04\x64iff\x18\x06 \x03(\x02\x42\x02\x10\x01\x12\x17\n\x0b\x64ouble_data\x18\x08 \x03(\x01\x42\x02\x10\x01\x12\x17\n\x0b\x64ouble_diff\x18\t \x03(\x01\x42\x02\x10\x01\x12\x0e\n\x03num\x18\x01 \x01(\x05:\x01\x30\x12\x13\n\x08\x63hannels\x18\x02 \x01(\x05:\x01\x30\x12\x11\n\x06height\x18\x03 \x01(\x05:\x01\x30\x12\x10\n\x05width\x18\x04 \x01(\x05:\x01\x30')




_BLOBSHAPE = _descriptor.Descriptor(
  name='BlobShape',
  full_name='caffe.BlobShape',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='dim', full_name='caffe.BlobShape.dim', index=0,
      number=1, type=3, cpp_type=2, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=_descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=22,
  serialized_end=50,
)


_BLOBPROTO = _descriptor.Descriptor(
  name='BlobProto',
  full_name='caffe.BlobProto',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='shape', full_name='caffe.BlobProto.shape', index=0,
      number=7, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='data', full_name='caffe.BlobProto.data', index=1,
      number=5, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=_descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')),
    _descriptor.FieldDescriptor(
      name='diff', full_name='caffe.BlobProto.diff', index=2,
      number=6, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=_descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')),
    _descriptor.FieldDescriptor(
      name='double_data', full_name='caffe.BlobProto.double_data', index=3,
      number=8, type=1, cpp_type=5, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=_descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')),
    _descriptor.FieldDescriptor(
      name='double_diff', full_name='caffe.BlobProto.double_diff', index=4,
      number=9, type=1, cpp_type=5, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=_descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')),
    _descriptor.FieldDescriptor(
      name='num', full_name='caffe.BlobProto.num', index=5,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='channels', full_name='caffe.BlobProto.channels', index=6,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='height', full_name='caffe.BlobProto.height', index=7,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='width', full_name='caffe.BlobProto.width', index=8,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=53,
  serialized_end=257,
)

_BLOBPROTO.fields_by_name['shape'].message_type = _BLOBSHAPE
DESCRIPTOR.message_types_by_name['BlobShape'] = _BLOBSHAPE
DESCRIPTOR.message_types_by_name['BlobProto'] = _BLOBPROTO

class BlobShape(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _BLOBSHAPE

  # @@protoc_insertion_point(class_scope:caffe.BlobShape)

class BlobProto(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _BLOBPROTO

  # @@protoc_insertion_point(class_scope:caffe.BlobProto)


_BLOBSHAPE.fields_by_name['dim'].has_options = True
_BLOBSHAPE.fields_by_name['dim']._options = _descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')
_BLOBPROTO.fields_by_name['data'].has_options = True
_BLOBPROTO.fields_by_name['data']._options = _descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')
_BLOBPROTO.fields_by_name['diff'].has_options = True
_BLOBPROTO.fields_by_name['diff']._options = _descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')
_BLOBPROTO.fields_by_name['double_data'].has_options = True
_BLOBPROTO.fields_by_name['double_data']._options = _descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')
_BLOBPROTO.fields_by_name['double_diff'].has_options = True
_BLOBPROTO.fields_by_name['double_diff']._options = _descriptor._ParseOptions(descriptor_pb2.FieldOptions(), '\020\001')
# @@protoc_insertion_point(module_scope)
