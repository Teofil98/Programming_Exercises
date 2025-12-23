program main
use dcp_1
implicit none
    integer, dimension(:), allocatable :: v
    integer :: n
    integer :: k
    integer :: ifile, ofile
    integer :: i
    logical :: l

    ! read input file
    open(newunit=ifile, file="input.txt", status="old", action="read")
    read(ifile, *) n
    allocate(v(n))
    read(ifile, *) (v(i), i = 1,n)
    read(ifile, *) k

    l = is_sum(v,k)

    open(newunit=ofile, file="output.txt", action="write")
    if (l) then
        write(ofile, "(a)") "True"
    else
        write(ofile, "(a)") "False"
    end if

    close(ofile)
    close(ifile)
    deallocate(v)
end program main
