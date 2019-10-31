str = "coolbeans"


def reverseString(str)
   turn_to_array = str.split('') # split CHARS into ARR
   reversed_string = ''

   turn_to_array.each do |char|
      reversed_string = char + reversed_string # EACH loop in RUBY only on ARRAYS
   end
   puts reversed_string
end

reverseString(str)