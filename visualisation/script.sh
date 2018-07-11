player_with_X="🍀 "
player_with_x="🍀 "
player_with_O="🌸 "
player_with_o="🌸 "
empty_place="⚪️ "

sed "s/O/$player_with_X/g" |
sed "s/X/$player_with_O/g" |
sed "/^0.. /s/x/$player_with_o/g" |
sed "/^0.. /s/o/$player_with_x/g" |
sed "/^0.. /s/\./$empty_place/g" 
