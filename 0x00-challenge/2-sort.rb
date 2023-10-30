###
#
#  Sort integer arguments (ascending) 
#
###

result = []
ARGV.each do |arg|
    # Skip if not an integer
    next unless arg =~ /^-?[0-9]+$/

    # Convert to integer
    i_arg = arg.to_i

    # Insert result at the right position
    i = 0
    while i < result.size && result[i] < i_arg do
        i += 1
    end

    result.insert(i, i_arg)
end

puts result
