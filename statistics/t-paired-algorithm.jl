using Statistics
using Printf

# ALPHA = 0.05
# CONFIDANCE = 0.95
# FREEDOM_DEGREE = SAMPLES - 1
CRITICAL_T = 2.093 # = t_{FREEDOM_DEGREE, ALPHA}
SAMPLES = 20

function main(ARGS)

    if (length(ARGS) < 2)
        println("Erro! Syntax: <Instance size> <algorithm>")
    end
    println("$(ARGS[2]) | Instance Size $(ARGS[1])")

    local size = parse(Int64, ARGS[1])
    local algorithm = ARGS[2]

    local output = readlines(open("$(@__DIR__)/../data/output/n$(size)/$(algorithm).out", "r"))
    local timeExecution = []

    for i = 3:22
        local time = parse(Float64, split(output[i], ": ")[2])
        push!(timeExecution, time)
    end

    local meanValue = mean(timeExecution)
    local stdValue = std(timeExecution) # Standard deviation

    local fstBound = meanValue + CRITICAL_T * stdValue / sqrt(SAMPLES)
    local sndBound = meanValue - CRITICAL_T * stdValue / sqrt(SAMPLES)

    local lowerbound = min(fstBound, sndBound)
    local upperbound = max(fstBound, sndBound)

    @printf("Confidance Interval: (%.4f;%.4f)", lowerbound, upperbound)

end

main(ARGS)

# If 0 is part of the confidance interval, both algorithms are similar 
# If not, then in this case, if the interval is < 0, algoritm 1 is better