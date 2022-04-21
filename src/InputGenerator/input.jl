function main(ARGS)

    if (length(ARGS) < 1)
        throw("É necessário 1 parâmetro. SYNTAX: julia input.jl <tamanho da instância>")
    end

    local size = parse(Int64, ARGS[1])

    for i = 1:20
        mkpath("$(@__DIR__)/../../data/output/n$(size)/")
        mkpath("$(@__DIR__)/../../data/input/n$(size)/")
        local file = open("$(@__DIR__)/../../data/input/n$(size)/instance-n$(size)-$(i).in", "w")

        local instance = zeros(Int64, size)
        for j = 1:size
            local randomNumber = 0
            randomNumber = rand(1:size)

            instance[j] = randomNumber
            write(file, "$(randomNumber)\n")
        end
    end

end


main(ARGS)