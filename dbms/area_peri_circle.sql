declare
radius number;
begin
radius:=&radius;
dbms_output.put_line('area= '||3.14*radius*radius);
dbms_output.put_line('perimeter= '||2*3.14*radius);
end;
/