using Statistics
using Printf

# ALPHA = 0.05
# CONFIDANCE = 0.95
# FREEDOM_DEGREE = SAMPLES - 1
CRITICAL_T = 2.093 # = t_{FREEDOM_DEGREE, ALPHA}
SAMPLES = 20

function main(ARGS)

    if (length(ARGS) < 3)
        println("Erro! Syntax: <Instance size> <algorithm> <another algorithm>")
    end
    println("$(ARGS[2]) - x - $(ARGS[3]) | Instance Size $(ARGS[1])")

    local size = parse(Int64, ARGS[1])
    local algorithm1 = ARGS[2]
    local algorithm2 = ARGS[3]

    local output1 = readlines(open("$(@__DIR__)/../data/output/n$(size)/$(algorithm1).out", "r"))
    local output2 = readlines(open("$(@__DIR__)/../data/output/n$(size)/$(algorithm2).out", "r"))
    local diff = []

    for i = 3:22
        local t1 = parse(Float64, split(output1[i], ": ")[2])
        local t2 = parse(Float64, split(output2[i], ": ")[2])
        push!(diff, t1 - t2)
    end

    local meanValue = mean(diff)
    local stdValue = std(diff) # Standard deviation

    local fstBound = meanValue + CRITICAL_T * stdValue / sqrt(SAMPLES)
    local sndBound = meanValue - CRITICAL_T * stdValue / sqrt(SAMPLES)

    local lowerbound = min(fstBound, sndBound)
    local upperbound = max(fstBound, sndBound)

    @printf("Confidance Interval: (%.4f;%.4f)", lowerbound, upperbound)

end

main(ARGS)

# If 0 is part of the confidance interval, both algorithms are similar 
# If not, then in this case, if the interval is < 0, algoritm 1 is better