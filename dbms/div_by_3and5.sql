declare
a number;
begin
a:=&a;
if (mod(a,3)=0 and mod(a,5)=0) then
dbms_output.put_line(a||' is divisible by 3 and 5');
else
dbms_output.put_line(a||' is not divisible by 3 and 5');
end if;
end;
/