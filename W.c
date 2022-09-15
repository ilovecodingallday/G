https://devhints.io/bash


bash


This is a quick reference to getting started with Bash scripting.

    Learn bash in y minutes
    (learnxinyminutes.com)
    Bash Guide
    (mywiki.wooledge.org)

Example

#!/usr/bin/env bash

NAME="John"
echo "Hello $NAME!"

Variables

NAME="John"
echo $NAME
echo "$NAME"
echo "${NAME}!"

String quotes

NAME="John"
echo "Hi $NAME"  #=> Hi John
echo 'Hi $NAME'  #=> Hi $NAME

Shell execution

echo "I'm in $(pwd)"
echo "I'm in `pwd`"
# Same

See Command substitution
Conditional execution

git commit && git push
git commit || echo "Commit failed"

Functions

get_name() {
  echo "John"
}

echo "You are $(get_name)"

See: Functions
Conditionals

if [[ -z "$string" ]]; then
  echo "String is empty"
elif [[ -n "$string" ]]; then
  echo "String is not empty"
fi

See: Conditionals
Strict mode

set -euo pipefail
IFS=$'\n\t'

See: Unofficial bash strict mode
Brace expansion

echo {A,B}.js

{A,B} 	Same as A B
{A,B}.js 	Same as A.js B.js
{1..5} 	Same as 1 2 3 4 5

See: Brace expansion
#Parameter expansions
Basics

name="John"
echo ${name}
echo ${name/J/j}    #=> "john" (substitution)
echo ${name:0:2}    #=> "Jo" (slicing)
echo ${name::2}     #=> "Jo" (slicing)
echo ${name::-1}    #=> "Joh" (slicing)
echo ${name:(-1)}   #=> "n" (slicing from right)
echo ${name:(-2):1} #=> "h" (slicing from right)
echo ${food:-Cake}  #=> $food or "Cake"

length=2
echo ${name:0:length}  #=> "Jo"

See: Parameter expansion

STR="/path/to/foo.cpp"
echo ${STR%.cpp}    # /path/to/foo
echo ${STR%.cpp}.o  # /path/to/foo.o
echo ${STR%/*}      # /path/to

echo ${STR##*.}     # cpp (extension)
echo ${STR##*/}     # foo.cpp (basepath)

echo ${STR#*/}      # path/to/foo.cpp
echo ${STR##*/}     # foo.cpp

echo ${STR/foo/bar} # /path/to/bar.cpp

STR="Hello world"
echo ${STR:6:5}   # "world"
echo ${STR: -5:5}  # "world"

SRC="/path/to/foo.cpp"
BASE=${SRC##*/}   #=> "foo.cpp" (basepath)
DIR=${SRC%$BASE}  #=> "/path/to/" (dirpath)

Substitution
${FOO%suffix} 	Remove suffix
${FOO#prefix} 	Remove prefix
${FOO%%suffix} 	Remove long suffix
${FOO##prefix} 	Remove long prefix
${FOO/from/to} 	Replace first match
${FOO//from/to} 	Replace all
${FOO/%from/to} 	Replace suffix
${FOO/#from/to} 	Replace prefix
Comments

# Single line comment

: '
This is a
multi line
comment
'

Substrings
${FOO:0:3} 	Substring (position, length)
${FOO:(-3):3} 	Substring from the right
Length
${#FOO} 	Length of $FOO
Manipulation

STR="HELLO WORLD!"
echo ${STR,}   #=> "hELLO WORLD!" (lowercase 1st letter)
echo ${STR,,}  #=> "hello world!" (all lowercase)

STR="hello world!"
echo ${STR^}   #=> "Hello world!" (uppercase 1st letter)
echo ${STR^^}  #=> "HELLO WORLD!" (all uppercase)

Default values
${FOO:-val} 	$FOO, or val if unset (or null)
${FOO:=val} 	Set $FOO to val if unset (or null)
${FOO:+val} 	val if $FOO is set (and not null)
${FOO:?message} 	Show error message and exit if $FOO is unset (or null)

Omitting the : removes the (non)nullity checks, e.g. ${FOO-val} expands to val if unset otherwise $FOO.
#Loops
Basic for loop

for i in /etc/rc.*; do
  echo $i
done

C-like for loop

for ((i = 0 ; i < 100 ; i++)); do
  echo $i
done

Ranges

for i in {1..5}; do
    echo "Welcome $i"
done

With step size

for i in {5..50..5}; do
    echo "Welcome $i"
done

Reading lines

cat file.txt | while read line; do
  echo $line
done

Forever

while true; do
  ···
done

#Functions
Defining functions

myfunc() {
    echo "hello $1"
}

# Same as above (alternate syntax)
function myfunc() {
    echo "hello $1"
}

myfunc "John"

Returning values

myfunc() {
    local myresult='some value'
    echo $myresult
}

result="$(myfunc)"

Raising errors

myfunc() {
  return 1
}

if myfunc; then
  echo "success"
else
  echo "failure"
fi

Arguments
$# 	Number of arguments
$* 	All positional arguments (as a single word)
$@ 	All positional arguments (as separate strings)
$1 	First argument
$_ 	Last argument of the previous command

Note: $@ and $* must be quoted in order to perform as described. Otherwise, they do exactly the same thing (arguments as separate strings).

See Special parameters.
#Conditionals
Conditions

Note that [[ is actually a command/program that returns either 0 (true) or 1 (false). Any program that obeys the same logic (like all base utils, such as grep(1) or ping(1)) can be used as condition, see examples.
[[ -z STRING ]] 	Empty string
[[ -n STRING ]] 	Not empty string
[[ STRING == STRING ]] 	Equal
[[ STRING != STRING ]] 	Not Equal
[[ NUM -eq NUM ]] 	Equal
[[ NUM -ne NUM ]] 	Not equal
[[ NUM -lt NUM ]] 	Less than
[[ NUM -le NUM ]] 	Less than or equal
[[ NUM -gt NUM ]] 	Greater than
[[ NUM -ge NUM ]] 	Greater than or equal
[[ STRING =~ STRING ]] 	Regexp
(( NUM < NUM )) 	Numeric conditions
More conditions
[[ -o noclobber ]] 	If OPTIONNAME is enabled
[[ ! EXPR ]] 	Not
[[ X && Y ]] 	And
[[ X || Y ]] 	Or
File conditions
[[ -e FILE ]] 	Exists
[[ -r FILE ]] 	Readable
[[ -h FILE ]] 	Symlink
[[ -d FILE ]] 	Directory
[[ -w FILE ]] 	Writable
[[ -s FILE ]] 	Size is > 0 bytes
[[ -f FILE ]] 	File
[[ -x FILE ]] 	Executable
[[ FILE1 -nt FILE2 ]] 	1 is more recent than 2
[[ FILE1 -ot FILE2 ]] 	2 is more recent than 1
[[ FILE1 -ef FILE2 ]] 	Same files
Example

# String
if [[ -z "$string" ]]; then
  echo "String is empty"
elif [[ -n "$string" ]]; then
  echo "String is not empty"
else
  echo "This never happens"
fi

# Combinations
if [[ X && Y ]]; then
  ...
fi

# Equal
if [[ "$A" == "$B" ]]

# Regex
if [[ "A" =~ . ]]

if (( $a < $b )); then
   echo "$a is smaller than $b"
fi

if [[ -e "file.txt" ]]; then
  echo "file exists"
fi

#Arrays
Defining arrays

Fruits=('Apple' 'Banana' 'Orange')

Fruits[0]="Apple"
Fruits[1]="Banana"
Fruits[2]="Orange"

Working with arrays

echo ${Fruits[0]}           # Element #0
echo ${Fruits[-1]}          # Last element
echo ${Fruits[@]}           # All elements, space-separated
echo ${#Fruits[@]}          # Number of elements
echo ${#Fruits}             # String length of the 1st element
echo ${#Fruits[3]}          # String length of the Nth element
echo ${Fruits[@]:3:2}       # Range (from position 3, length 2)
echo ${!Fruits[@]}          # Keys of all elements, space-separated

Operations

Fruits=("${Fruits[@]}" "Watermelon")    # Push
Fruits+=('Watermelon')                  # Also Push
Fruits=( ${Fruits[@]/Ap*/} )            # Remove by regex match
unset Fruits[2]                         # Remove one item
Fruits=("${Fruits[@]}")                 # Duplicate
Fruits=("${Fruits[@]}" "${Veggies[@]}") # Concatenate
lines=(`cat "logfile"`)                 # Read from file

Iteration

for i in "${arrayName[@]}"; do
  echo $i
done

#Dictionaries
Defining

declare -A sounds

sounds[dog]="bark"
sounds[cow]="moo"
sounds[bird]="tweet"
sounds[wolf]="howl"

Declares sound as a Dictionary object (aka associative array).
Working with dictionaries

echo ${sounds[dog]} # Dog's sound
echo ${sounds[@]}   # All values
echo ${!sounds[@]}  # All keys
echo ${#sounds[@]}  # Number of elements
unset sounds[dog]   # Delete dog

Iteration
Iterate over values

for val in "${sounds[@]}"; do
  echo $val
done

Iterate over keys

for key in "${!sounds[@]}"; do
  echo $key
done

#Options
Options

set -o noclobber  # Avoid overlay files (echo "hi" > foo)
set -o errexit    # Used to exit upon error, avoiding cascading errors
set -o pipefail   # Unveils hidden failures
set -o nounset    # Exposes unset variables

Glob options

shopt -s nullglob    # Non-matching globs are removed  ('*.foo' => '')
shopt -s failglob    # Non-matching globs throw errors
shopt -s nocaseglob  # Case insensitive globs
shopt -s dotglob     # Wildcards match dotfiles ("*.sh" => ".foo.sh")
shopt -s globstar    # Allow ** for recursive matches ('lib/**/*.rb' => 'lib/a/b/c.rb')

Set GLOBIGNORE as a colon-separated list of patterns to be removed from glob matches.
#History
Commands
history 	Show history
shopt -s histverify 	Don’t execute expanded result immediately
Expansions
!$ 	Expand last parameter of most recent command
!* 	Expand all parameters of most recent command
!-n 	Expand nth most recent command
!n 	Expand nth command in history
!<command> 	Expand most recent invocation of command <command>
Operations
!! 	Execute last command again
!!:s/<FROM>/<TO>/ 	Replace first occurrence of <FROM> to <TO> in most recent command
!!:gs/<FROM>/<TO>/ 	Replace all occurrences of <FROM> to <TO> in most recent command
!$:t 	Expand only basename from last parameter of most recent command
!$:h 	Expand only directory from last parameter of most recent command

!! and !$ can be replaced with any valid expansion.
Slices
!!:n 	Expand only nth token from most recent command (command is 0; first argument is 1)
!^ 	Expand first argument from most recent command
!$ 	Expand last token from most recent command
!!:n-m 	Expand range of tokens from most recent command
!!:n-$ 	Expand nth token to last from most recent command

!! can be replaced with any valid expansion i.e. !cat, !-2, !42, etc.
#Miscellaneous
Numeric calculations

$((a + 200))      # Add 200 to $a

$(($RANDOM%200))  # Random number 0..199

Subshells

(cd somedir; echo "I'm now in $PWD")
pwd # still in first directory

Redirection

python hello.py > output.txt   # stdout to (file)
python hello.py >> output.txt  # stdout to (file), append
python hello.py 2> error.log   # stderr to (file)
python hello.py 2>&1           # stderr to stdout
python hello.py 2>/dev/null    # stderr to (null)
python hello.py &>/dev/null    # stdout and stderr to (null)

python hello.py < foo.txt      # feed foo.txt to stdin for python

Inspecting commands

command -V cd
#=> "cd is a function/alias/whatever"

Trap errors

trap 'echo Error at about $LINENO' ERR

or

traperr() {
  echo "ERROR: ${BASH_SOURCE[1]} at about ${BASH_LINENO[0]}"
}

set -o errtrace
trap traperr ERR

Case/switch

case "$1" in
  start | up)
    vagrant up
    ;;

  *)
    echo "Usage: $0 {start|stop|ssh}"
    ;;
esac

Source relative

source "${0%/*}/../share/foo.sh"

printf

printf "Hello %s, I'm %s" Sven Olga
#=> "Hello Sven, I'm Olga

printf "1 + 1 = %d" 2
#=> "1 + 1 = 2"

printf "This is how you print a float: %f" 2
#=> "This is how you print a float: 2.000000"

Directory of script

DIR="${0%/*}"

Getting options

while [[ "$1" =~ ^- && ! "$1" == "--" ]]; do case $1 in
  -V | --version )
    echo $version
    exit
    ;;
  -s | --string )
    shift; string=$1
    ;;
  -f | --flag )
    flag=1
    ;;
esac; shift; done
if [[ "$1" == '--' ]]; then shift; fi

Heredoc

cat <<END
hello world
END

Reading input

echo -n "Proceed? [y/n]: "
read ans
echo $ans

read -n 1 ans    # Just one character

Special variables
$? 	Exit status of last task
$! 	PID of last background task
$$ 	PID of shell
$0 	Filename of the shell script
$_ 	Last argrument of the previous command

See Special parameters.
Go to previous directory

pwd # /home/user/foo
cd bar/
pwd # /home/user/foo/bar
cd -
pwd # /home/user/foo

Check for command’s result

if ping -c 1 google.com; then
  echo "It appears you have a working internet connection"
fi

Grep check

if grep -q 'foo' ~/.bash_history; then
  echo "You appear to have typed 'foo' in the past"
fi

#Also see

    Bash-hackers wiki (bash-hackers.org)
    Shell vars (bash-hackers.org)
    Learn bash in y minutes (learnxinyminutes.com)
    Bash Guide (mywiki.wooledge.org)
    ShellCheck (shellcheck.net)

/
Over 356 curated cheatsheets, by developers for developers. Devhints home
Other CLI cheatsheets

    Cron
    cheatsheet
    Homebrew
    cheatsheet
    httpie
    cheatsheet
    adb (Android Debug Bridge)
    cheatsheet
    composer
    cheatsheet
    Fish shell
    cheatsheet

Top cheatsheets

    Elixir
    cheatsheet
    ES2015+
    cheatsheet
    React.js
    cheatsheet
    Vimdiff
    cheatsheet
    Vim
    cheatsheet
    Vim scripting
    cheatsheet


https://devhints.io/grep


grep

grep <options> pattern <file...>

Matching options

-e, --regexp=PATTERN
-f, --file=FILE
-i, --ignore-case
-v, --invert-match
-w, --word-regexp
-x, --line-regexp

Pattern options

-F, --fixed-strings   # list of fixed strings
-G, --basic-regexp    # basic regular expression (default)
-E, --extended-regexp # extended regular expression
-P, --perl-regexp     # perl compatible regular expression

Expressions
Basic Regular Expressions (BRE)

In BRE, these characters have a special meaning unless they are escaped with a backslash:

^ $ . * [ ] \

However, these characters do not have any special meaning unless they are escaped with a backslash:

? + { } | ( )
Extended Regular Expressions (ERE)

ERE gives all of these characters a special meaning unless they are escaped with a backslash:

^ $ . * + ? [ ] ( ) | { }
Perl Compatible Regular Expressions (PCRE)

PCRE has even more options such as additional anchors and character classes, lookahead/lookbehind, conditional expressions, comments, and more. See the regexp cheatsheet.
Output Options

-c, --count           # print the count of matching lines. suppresses normal output
    --color[=WHEN]    # applies color to the matches. WHEN is never, always, or auto
-m, --max-count=NUM   # stop reading after max count is reached
-o, --only-matching   # only print the matched part of a line
-q, --quiet, --silent
-s, --no-messages     # suppress error messages about nonexistent or unreadable files

Context Options

-B NUM, --before-context=NUM  # print NUM lines before a match
-A NUM, --after-context=NUM   # print NUM lines after a match
-C NUM, -NUM, --context=NUM   # print NUM lines before and after a match

Examples

# Case insensitive: match any line in foo.txt
# that contains "bar"
grep -i bar foo.txt

#  match any line in bar.txt that contains
# either "foo" or "oof"
grep -E "foo|oof" bar.txt

# match anything that resembles a URL in
# foo.txt and only print out the match
grep -oE "https?:\/\/((\w+[_-]?)+\.?)+" foo.txt

# can also be used with pipes:
# match any line that contains "export" in
# .bash_profile, pipe to another grep that
# matches any of the first set of matches
# containing "PATH"
grep "export" .bash_profile | grep "PATH"

# follow the tail of server.log, pipe to grep
# and print out any line that contains "error"
# and include 5 lines of context
tail -f server.log | grep -iC 5 error


https://devhints.io/sed


sed 


sed -i -e 's/foo/bar/' example.md

In GNU sed: use -i without arg.
In-place replacement (BSD)

sed -i '' -e 's/foo/bar/' example.md

In OSX, -i '' is required.
#File regions
Print until a certain line is met

sed '/begin api/q'

Print until a certain line is met, but not that line

sed '/^# begin/,$d'

Print everything after a given line

sed -n '/end api/,$p'

Print after a given line is found.
Print everything except matching

sed -n '/regex/d;'



=================================================================================================================
=================================================================================================================
=================================================================================================================









Curl 
Options

-o <file>    # --output: write to file
-u user:pass # --user: Authentication

-v           # --verbose
-vv          # Even more verbose
-s           # --silent: don't show progress meter or errors
-S           # --show-error: when used with --silent (-sS), show errors but no progress meter

-i           # --include: Include the HTTP-header in the output
-I           # --head: headers only

Request

-X POST          # --request
-L               # follow link if page redirects
-F 	             # --form: HTTP POST data for multipart/form-data

Data

-d 'data'    # --data: HTTP post data, URL encoded (eg, status="Hello")
-d @file     # --data via file
-G           # --get: send -d data via get

Headers

-A <str>         # --user-agent
-b name=val      # --cookie
-b FILE          # --cookie
-H "X-Foo: y"    # --header
--compressed     # use deflate/gzip

SSL

    --cacert <file>
    --capath <dir>

-E, --cert <cert>     # --cert: Client cert file
    --cert-type       # der/pem/eng
-k, --insecure        # for self-signed certs

#Examples

# Post data:
curl -d password=x http://x.com/y

# Auth/data:
curl -u user:pass -d status="Hello" http://twitter.com/statuses/update.xml

# multipart file upload
curl -v -include --form key1=value1 --form upload=@localfilename URL

# multipart form: send data from text field and upload file
curl -F person=anonymous -F secret=@file.txt http://example.com/submit.cgi

# Use Curl to Check if a remote resource is available
# details: https://matthewsetter.com/check-if-file-is-available-with-curl/
curl -o /dev/null --silent -Iw "%{http_code}" https://example.com/my.remote.tarball.gz


=================================================================================================================
=================================================================================================================
=================================================================================================================








