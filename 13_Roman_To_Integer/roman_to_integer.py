#https://leetcode.com/problems/roman-to-integer/submissions/919114941/

class Solution:
    def romanToInt(self, s: str) -> int:

        # Store result
        result = 0

        str_len = len(s)

        # start at the front
        index = 0

        # Go through all the letters
        while index < str_len:
            # Get the current letter
            cur_ltr = s[index]

            if cur_ltr == "I":
                # Check for a prefix for I
                if index + 1 < str_len and (s[index + 1] == "V" or s[index + 1] == "X"):
                    if s[index + 1] == "V":
                        result += 4
                        index += 1
                    elif s[index + 1] == "X":
                        result += 9
                        index += 1
                else:
                    result += 1
            elif cur_ltr == "X":
                # Check for a prefix for X
                if index + 1 < str_len and (s[index + 1] == "L" or s[index + 1] == "C") :
                    if s[index + 1] == "L":
                        result += 40
                        index += 1
                    elif s[index + 1] == "C":
                        result += 90
                        index += 1
                else:
                    result += 10
            elif cur_ltr == "C":
                # Check for a prefix for C
                if index + 1 < str_len and (s[index + 1] == "D" or s[index + 1] == "M") :
                    if s[index + 1] == "D":
                        result += 400
                        index += 1
                    elif s[index + 1] == "M":
                        result += 900
                        index += 1
                else:
                    result += 100
            elif cur_ltr == "V":
                result += 5
            elif cur_ltr == "L":
                result += 50
            elif cur_ltr == "D":
                result += 500
            elif cur_ltr == "M":
                result += 1000

            # Move the index
            index += 1

        return result