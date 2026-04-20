from collections import deque


class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        queue = deque([(beginWord, 1)])

        while queue:
            word, length = queue.popleft()

            if word == endWord:
                return length

            for i in range(len(word)):
                for c in "abcdefghijklmnopqrstuvwxyz":
                    newWord = word[:i] + c + word[i + 1:]

                    if newWord in wordSet:
                        wordSet.remove(newWord)
                        queue.append((newWord, length + 1))

        return 0


if __name__ == "__main__":
    obj = Solution()

    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log", "cog"]

    print(obj.ladderLength(beginWord, endWord, wordList))
