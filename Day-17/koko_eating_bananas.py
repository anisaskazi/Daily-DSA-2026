class Solution:
    def minEatingSpeed(self, piles, h):
        left = 1
        right = max(piles)
        answer = right

        while left <= right:
            mid = (left + right) // 2
            total_hours = 0

            for bananas in piles:
                total_hours += (bananas + mid - 1) // mid

            if total_hours <= h:
                answer = mid
                right = mid - 1
            else:
                left = mid + 1

        return answer


if __name__ == "__main__":
    obj = Solution()
    piles = [3, 6, 7, 11]
    h = 8

    result = obj.minEatingSpeed(piles, h)
    print(result)
