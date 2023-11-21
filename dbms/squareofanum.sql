declare
a number;
begin
a:=&a;
dbms_output.put_line(a||'^2'||' = '||a*a);
end;
/