declare
a number;
b number;
c number;
begin
a:=&a;
b:=&b;
dbms_output.put_line('before swapping : '||a||' '||b);
c:=a;
a:=b;
b:=c;
dbms_output.put_line('after swapping : '||a||' '||b);
end;
/
