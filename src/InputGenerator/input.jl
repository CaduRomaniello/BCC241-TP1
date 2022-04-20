function main(ARGS)

    if (length(ARGS) < 1)
        throw("É necessário 1 parâmetro. SYNTAX: julia input.jl <instance size>")
    end

    local size = parse(Int64, ARGS[1])

    for i = 1:20
        mkpath("../../data/input/n$(size)/")
        local file = open("../../data/input/n$(size)/instance-n$(size)-$(i).in", "w")
        write(file, "$(size)\n")

        local instance = zeros(Int64, size)
        for j = 1:size
            local randomNumber = 0

            while true
                randomNumber = rand(1:size)

                if !(randomNumber in instance)
                    break
                end
            end

            instance[j] = randomNumber
            write(file, "$(randomNumber)\n")
        end
    end

end


main(ARGS)