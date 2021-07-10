import 'dart:ffi';
import 'dart:io' show Directory;

import 'package:ffi/ffi.dart';
import 'package:path/path.dart' as path;

class Node extends Struct {
  @Uint64()
  external int data;

  @Uint64()
  external int key;

  external Pointer<Node> next;
}
