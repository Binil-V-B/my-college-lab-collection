declare
a number;
begin
a:=&a;
if(mod(a,2)=0) then
dbms_output.put_line(a||' is even');
else
dbms_output.put_line(a||' is odd');
end if;
end;
/