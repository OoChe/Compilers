
 line       object           ucode  source program

   1    (35    1    2)     main       proc           1     2     2
   2    (38    2    1)                sym            2     1     1
   3    (20  333     )                ldc          333
   4    (24    2    1)                str            2     1
   5    (19    2    1)                lod            2     1
   6    ( 2          )                inc       
   7    (24    2    1)                str            2     1
   8    (23          )                ldp       
   9    (19    2    1)                lod            2     1
  10    (29   -2     )                call       write
  11    (19    2    1)                lod            2     1
  12    (20   10     )                ldc           10
  13    (10          )                mod       
  14    (24    2    1)                str            2     1
  15    (23          )                ldp       
  16    (19    2    1)                lod            2     1
  17    (29   -2     )                call       write
  18    (30          )                ret       
  19    (36          )                end       
  20    (37    0     )                bgn            0
  21    (23          )                ldp       
  22    (29    1     )                call       main
  23    (36          )                end       


   ****    Result    ****

 334 4


             ##### Statistics #####


    ****  Static Instruction Counts  ****

inc    =  1       mod    =  1       lod    =  4       ldc    =  2       
ldp    =  3       str    =  3       call   =  3       ret    =  1       
proc   =  1       end    =  2       bgn    =  1       sym    =  1       


    ****  Dynamic instruction counts  ****

inc    =  1         mod    =  1         lod    =  4         ldc    =  2         
ldp    =  3         str    =  3         call   =  3         ret    =  1         
proc   =  1         end    =  1         bgn    =  1         sym    =  1         


 Executable instruction count  =   19

 Total execution cycle         =   326
