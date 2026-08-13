(* Test of initial values for structured/array data types. *)

TYPE
  arr_2d : ARRAY [1..2, 1..3] OF DINT;
  arr_of_2d : ARRAY [1..2] OF arr_2d;
END_TYPE

PROGRAM program0
  VAR
    count : DINT;
    v : arr_of_2d := [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12]];
  END_VAR

  count := count + 1;
END_PROGRAM

CONFIGURATION config
  RESOURCE resource1 ON PLC
    TASK main_task(INTERVAL := T#1000ms, PRIORITY := 0);
    PROGRAM instance0 WITH main_task : program0;
  END_RESOURCE
END_CONFIGURATION
