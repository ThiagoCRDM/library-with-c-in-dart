import 'dart:ffi';
import 'dart:io' show Directory;

import 'package:path/path.dart' as path;

class Node extends Struct {
  @Int64()
  external int data;

  @Int64()
  external int key;

  external Pointer<Node> next;
}

typedef PrintListFunc = Void Function();
typedef PrintList = void Function();

typedef InsertFirstFunc = Void Function(Int64 key, Int64 data);
typedef InsertFirst = void Function(int key, int data);

typedef DeleteFirstFunc = Pointer<Node> Function();
typedef DeleteFirst = Pointer<Node> Function();

typedef IsEmptyFunc = Int64 Function();
typedef IsEmpty = int Function();

typedef LengthFunc = Int64 Function();
typedef Length = int Function();

typedef FindFunc = Pointer<Node> Function(Int64 key);
typedef Find = Pointer<Node> Function(int key);

typedef DeleteFunc = Pointer<Node> Function(Int64 key);
typedef Delete = Pointer<Node> Function(int key);

typedef SortFunc = Void Function();
typedef Sort = void Function();

typedef ReverseFunc = Void Function(Pointer<Pointer<Node>> head);
typedef Reverse = void Function(Pointer<Pointer<Node>> head);

void main() {
  var libraryPath = path.join(
    Directory.current.path,
    'bin',
    'src',
    'c',
    'data_structure',
    'linked_list',
    'libdata_struct_linked_list.so',
  );

  final dynamicLib = DynamicLibrary.open(libraryPath);

  final insertFirst =
      dynamicLib.lookupFunction<InsertFirstFunc, InsertFirst>('insertFirst');

  final printList =
      dynamicLib.lookupFunction<PrintListFunc, PrintList>('printList');

  final length = dynamicLib.lookupFunction<LengthFunc, Length>('length');

  final deleteFirst =
      dynamicLib.lookupFunction<DeleteFirstFunc, DeleteFirst>('deleteFirst');

  final isEmpty = dynamicLib.lookupFunction<IsEmptyFunc, IsEmpty>('isEmpty');

  final find = dynamicLib.lookupFunction<FindFunc, Find>('find');

  final delete = dynamicLib.lookupFunction<DeleteFunc, Delete>('delete');

  final sort = dynamicLib.lookupFunction<SortFunc, Sort>('sort');

  final reverse = dynamicLib.lookupFunction<ReverseFunc, Reverse>('reverse');

  insertFirst(1, 10);
  insertFirst(2, 20);
  insertFirst(3, 30);
  insertFirst(4, 1);
  insertFirst(5, 40);
  insertFirst(6, 56);

  printList();

  while (isEmpty() == 1) {
    var temp = deleteFirst();
    print('Deleted value');
    print('${temp.ref.data} ${temp.ref.key}');
  }

  print('List after deleting all items: ');
  printList();

  insertFirst(1, 10);
  insertFirst(2, 20);
  insertFirst(3, 30);
  insertFirst(4, 1);
  insertFirst(5, 40);
  insertFirst(6, 56);

  print('Restored List: ');
  printList();
  print('');

  var foundLink = find(4);

  // ignore: unnecessary_null_comparison
  if (foundLink.address != null) {
    print('Element found: ');
    print('${foundLink.ref.key.floor()},${foundLink.ref.data.floor()}');
  } else {
    print('Element not found.');
  }

  foundLink = find(4);

// ignore: unnecessary_null_comparison
  if (foundLink.address != null) {
    print('Element found: ');
    print('${foundLink.ref.key.floor()},${foundLink.ref.data.floor()}');
    print('');
  } else {
    print('Element not found.');
  }

  sort();

  print('List after sorting the data: ');
  printList();

  sort();
}
