import 'dart:ffi';
import 'dart:io' show Directory;

import 'package:path/path.dart' as path;

typedef EnQueueFunc = Void Function(Int64 value);

typedef EnQueue = void Function(int value);

typedef DeQueueFunc = Void Function();

typedef DeQueue = void Function();

typedef DisplayFunc = Void Function();

typedef Display = void Function();

void main() {
  var libraryPath = path.join(
    Directory.current.path,
    'bin',
    'src',
    'c',
    'data_structure',
    'queue',
    'libdata_struct_queue.so',
  );

  final dynamicLib = DynamicLibrary.open(libraryPath);

  // ignore: omit_local_variable_types
  final EnQueue enQueue =
      dynamicLib.lookup<NativeFunction<EnQueueFunc>>('enQueue').asFunction();
  // ignore: omit_local_variable_types
  final Display display =
      dynamicLib.lookup<NativeFunction<DeQueueFunc>>('display').asFunction();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(8);

  display();
}
