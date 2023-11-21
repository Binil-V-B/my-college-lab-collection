declare
l number;
b number;
begin
l:=&l;
b:=&b;
dbms_output.put_line('area= '||l*b);
dbms_output.put_line('perimeter= '||2*(l+b));
end;
/