
xmake clean -a
set VM_64bit=1
xmake f -a x86 -y
xmake -y -w -v
