def foo() {
  var s: sync int;
  begin {
    s.readFE();
    writeln("2. hello, world");
  }
  begin {
    writeln("1. hello, world");
    s = 1;
  }
}

end foo();

writeln("3. hello, world");
