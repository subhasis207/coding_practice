#!/usr/bin/ruby
def max(*values)
#	values = values.delete_if{|val| if not val}
	return values.max
end

def min(*values)
#	values = values.delete_if{|val| if not val}
	return values.min
end 

def lcs_length(str_1,str_2)
	len1 = str_1.size
	len2 = str_2.size
	match_indices = Array.new(len1+2,Array.new(len2+2,0))
	(0..len1).each do |i|
		match_indices[i][0] = 0
	end
	(0..len2).each do |j|
		match_indices[0][j] = 0
	end
	(1..(len1+1.to_i)).each do |i|
		(1..(len2+1).to_i).each do |j|
			if str_1[i-1] == str_2[j-1]
				match_indices[i][j] = match_indices[i-1][j-1] + 1
			else
				match_indices[i][j] = max(match_indices[i][j-1], match_indices[i-1][j])
			end
		end
	end
	return match_indices
end

def lcs_backtrack(match_arr,str_1,str_2,i,j)
	if i == 0 or j == 0
		return ""
	elsif str_1[i-1] == str_2[j-1]
		return lcs_backtrack(match_arr, str_1, str_2, i-1, j-1) + str_1[i-1]
	else
		if match_arr[i][j-1] > match_arr[i-1][j]
			return lcs_backtrack(match_arr,str_1, str_2, i, j-1)
		else
			return lcs_backtrack(match_arr, str_1, str_2, i-1, j)
		end
	end
end

def lcs_backtrack_all(match_arr,str_1,str_2,i,j)
	if i == 0 or j == 0
		return [""]
	elsif str_1[i-1] == str_2[j-1]
		final_set = []
		all_match_arr = lcs_backtrack_all(match_arr,str_1,str_2,i-1,j-1)
		all_match_arr.each do |match_ar|
			match_ar = match_ar + str_1[i-1]
			final_set << match_ar
		end
		final_set.uniq!
		return final_set
	else
		output_set = []
		if match_arr[i][j-1] >= match_arr[i-1][j]
			output_set.push(lcs_backtrack_all(match_arr, str_1, str_2, i, j-1))
		end
		if match_arr[i-1][j] >= match_arr[i][j-1]
			output_set.push(lcs_backtrack_all(match_arr, str_1, str_2, i-1, j))
		end
		output_set.flatten!
		output_set.uniq!
		return output_set
	end
end
if __FILE__ == $0
	str_1 = gets.chomp.strip  
	str_2 = gets.chomp.strip
	costs = gets.chomp.strip
	cost_arr = costs.split(" ")
	len1 = str_1.size
	len2 = str_2.size
	value_arr = ["2","3","5","7"]
	match_arr = lcs_length(str_1,str_2)
	output_set = lcs_backtrack_all(match_arr,str_1, str_2,len1,len2)
	output_set = output_set.delete_if{|sub| sub.nil? or sub.empty? }
	min_value = 0
	output_set.each_with_index do |lcs,index|
		each_ltr = []
		each_ltr = each_ltr + lcs.split("") if lcs.size > 1
		each_ltr << lcs if lcs.size == 1
		missing_arr = str_2.split("") - each_ltr
		sum = 0
		missing_arr.each do |missing|
			missing = missing.to_i
			if missing == 2
				sum = sum+(cost_arr[0].to_i)
			elsif missing == 3
				sum = sum+(cost_arr[1].to_i)
			elsif missing == 5
				sum = sum+(cost_arr[2].to_i)
			elsif missing == 7
				sum = sum+(cost_arr[3].to_i)
			end
		end
		min_value = sum if index == 0
		min_value = min(sum.to_i,min_value.to_i)
	end
	puts min_value
end
