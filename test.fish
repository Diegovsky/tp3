for strat in BMH Naive
    for f in (ls inputs)
        echo "[$strat] :: "
        if ./tp3 $strat | rg -i 'Diferença'
            echo -e "\e[31mFalha"
        else
            echo -e "\e[32mSucesso"
        end

            echo -e "\e[0mSucesso"

    end
end
