
xmake clean -a
set VM_64bit=1
set LUAT_USE_GUI=n
xmake f -a x86 -y
xmake -y -w -v
