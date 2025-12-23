module dcp_1
implicit none
    private
    public is_sum

contains

function is_sum(v, k) result(res)
    integer, intent(in) :: v(:)
    integer, intent(in) :: k
    logical :: res
    integer :: i, j
    res = .false.
    do i = 1, (size(v) - 1)
        do j = i + 1, size(v)
            if (v(i) + v(j) == k) then
                res = .true.
            end if
        end do
    end do
end function is_sum

end module dcp_1
