module test2
use test1
implicit none
    private
    public print2

contains

    subroutine print2()
        print *,"Will call print1"
        call print1()
    end subroutine print2

end module test2
