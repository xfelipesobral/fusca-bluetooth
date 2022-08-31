import { StyleSheet, Text, View } from 'react-native'
import { MaterialCommunityIcons } from '@expo/vector-icons'
import LottieView from 'lottie-react-native'

import aniFusca from '../../assets/animations/fusca.json'

function corBlueetoh(status = false) {
    const opacidade = 0.95

    const cores = {
        'true': `rgba(0, 169, 101, ${opacidade})`,
        'false': `rgba(255, 5, 5, ${opacidade})`
    }

    return cores[String(status)] || `rgba(255, 132, 0, ${opacidade})`
}

function Cabecalho({ bluetoothStatus }) {

    return (
        <View style={estilos.container}>
            <View>
                <View style={[estilos.icone, { backgroundColor: corBlueetoh(bluetoothStatus) }]}>
                    {
                        bluetoothStatus ?
                            <MaterialCommunityIcons size={70} name='bluetooth' color='#fff' /> :
                            <MaterialCommunityIcons size={70} name='bluetooth-off' color='#fff' />
                    }
                </View>
                <LottieView
                    style={{
                        height: 150,
                        marginBottom: 25
                    }}
                    source={aniFusca}
                    autoPlay={true}
                    loop={true}
                    resizeMode='cover'
                />
            </View>
            <Text style={{
                fontSize: 24,
                fontWeight: 'bold',
                marginVertical: 5
            }}>Fusca Bluetooth</Text>
            <Text style={{ textAlign: 'center' }}>Licenciatura em Computação{'\n'}UFPR Palotina</Text>
        </View>
    )
}

const estilos = StyleSheet.create({
    icone: {
        position: 'absolute',
        zIndex: 1000,
        padding: 5,
        borderRadius: 100,
        right: 10,
        top: -20
    },

    container: {
        flex: 1,
        alignItems: 'center',
        marginTop: 70
    },
})


export default Cabecalho