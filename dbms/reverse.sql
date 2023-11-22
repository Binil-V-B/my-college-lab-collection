declare
a number;
s number;
rem number;
begin
a:=&a;
s:=0;
while a>0 loop
rem:=mod(a,10);
s:=s*10+rem;
a:=floor(a/10);
end loop;
dbms_output.put_line('reverse = '||s);
end;
/
